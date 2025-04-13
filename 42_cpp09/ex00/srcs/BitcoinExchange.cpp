#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

template <typename T>
typename T::const_iterator getLastIterator(const T& map) {
  typename T::const_iterator lastIt;
  for (typename T::const_iterator it = map.begin(); it != map.end(); ++it) {
    lastIt = it;
  }
  return lastIt;
}

BitcoinExchange::BitcoinExchange(const std::string& bitcoinFile)
    : bitcoinFile(bitcoinFile) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
  *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    this->bitcoinFile = other.bitcoinFile;
  }
  return *this;
}

int BitcoinExchange::process(const std::string& inputFile) {
  try {
    YearBitcoin bitcoin = getBitcoin();
    return validateInputFile(bitcoin, inputFile);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return ERROR;
  }
}

void BitcoinExchange::addBitcoin(YearBitcoin& map, const std::string& line) {
  int year, month, day;
  float value;
  char dash;
  std::istringstream stream(line);
  stream >> year >> dash >> month >> dash >> day >> dash >> value;
  map[year][month][day] = value;
}

YearBitcoin BitcoinExchange::getBitcoin() {
  std::ifstream file(this->bitcoinFile);
  if (!file.is_open()) {
    throw std::runtime_error("CSV File not found");
  }

  std::string line;
  if (!std::getline(file, line)) {
    throw std::runtime_error("Unable to read the header line in CSV file");
  }
  YearBitcoin map;
  if (line != "date,exchange_rate") {
    throw std::runtime_error("Invalid header line in CSV file");
  }
  while (std::getline(file, line)) {
    addBitcoin(map, line);
  }
  return map;
}

void printBitcoin(const YearBitcoin& bitcoin) {
  for (YearBitcoin::const_iterator yearIt = bitcoin.begin();
       yearIt != bitcoin.end(); ++yearIt) {
    std::cout << "Year: " << yearIt->first << std::endl;
    for (MonthBitcoin::const_iterator monthIt = yearIt->second.begin();
         monthIt != yearIt->second.end(); ++monthIt) {
      std::cout << "  Month: " << monthIt->first << std::endl;
      for (DayBitcoin::const_iterator dayIt = monthIt->second.begin();
           dayIt != monthIt->second.end(); ++dayIt) {
        std::cout << "    Day: " << dayIt->first
                  << " - Value: " << dayIt->second << std::endl;
      }
    }
  }
}

void printCalculatedBitcoin(const YearBitcoin& bitcoin) {
  for (YearBitcoin::const_iterator yearIt = bitcoin.begin();
       yearIt != bitcoin.end(); ++yearIt) {
    std::cout << "Year: " << yearIt->first << std::endl;
    for (MonthBitcoin::const_iterator monthIt = yearIt->second.begin();
         monthIt != yearIt->second.end(); ++monthIt) {
      std::cout << "  Month: " << monthIt->first << std::endl;
      for (DayBitcoin::const_iterator dayIt = monthIt->second.begin();
           dayIt != monthIt->second.end(); ++dayIt) {
        std::cout << "    Day: " << dayIt->first
                  << " - Value: " << dayIt->second << std::endl;
      }
    }
  }
}

void BitcoinExchange::processInputLine(const YearBitcoin& bitcoin,
                                       const std::string& line) {
  std::istringstream stream(line);
  float input_value;
  int input_year, input_month, input_day;

  size_t delim_pos = line.find(" | ");
  if (delim_pos == std::string::npos) {
    std::cerr << "Error: missing or invalid delimiter => \"" << line << "\""
              << std::endl;
    return;
  }

  if (line.find(" | ", delim_pos + 3) != std::string::npos) {
    std::cerr << "Error: multiple delimiters => \"" << line << "\""
              << std::endl;
    return;
  }

  if (line[0] == ' ' || line[line.size() - 1] == ' ') {
    std::cerr << "Error: leading or trailing space => \"" << line << "\""
              << std::endl;
    return;
  }

  std::string date_str = line.substr(0, delim_pos);
  std::string value_str = line.substr(delim_pos + 3);

  if (date_str.size() != 10 || date_str[4] != '-' || date_str[7] != '-') {
    std::cerr << "Error: bad date format => \"" << date_str << "\""
              << std::endl;
    return;
  }
  for (size_t i = 0; i < date_str.size(); ++i) {
    if ((i == 4 || i == 7)) continue;
    if (!isdigit(date_str[i])) {
      std::cerr << "Error: bad date format => \"" << date_str << "\""
                << std::endl;
      return;
    }
  }

  char* endptr;
  input_value = std::strtof(value_str.c_str(), &endptr);

  if (*endptr != '\0') {
    std::cerr << "Error: invalid numeric value => \"" << value_str << "\""
              << std::endl;
    return;
  }

  if (input_value < 0.0f || input_value > 1000.0f) {
    std::cerr << "Error: value out of range (0 ~ 1000) => " << input_value
              << std::endl;
    return;
  }

  if (std::sscanf(date_str.c_str(), "%d-%d-%d", &input_year, &input_month,
                  &input_day) != 3) {
    std::cerr << "Error: bad date format => \"" << date_str << "\""
              << std::endl;
    return;
  }

#ifdef DEBUG
  std::cout << "Parsed: " << input_year << "-" << input_month << "-"
            << input_day << " | value = " << input_value << std::endl;
#endif

  YearBitcoin::const_iterator firstYearIt = bitcoin.begin();
  YearBitcoin::const_iterator lastYearIt = getLastIterator(bitcoin);
  if (input_year < firstYearIt->first || input_year > lastYearIt->first) {
    std::cerr << "Error: year " << input_year << " not in range ("
              << firstYearIt->first << "~" << lastYearIt->first << ")"
              << std::endl;
    return;
  }

  YearBitcoin::const_iterator yearIt = bitcoin.find(input_year);
  if (yearIt == bitcoin.end()) {
    std::cerr << "Error: year " << input_year << " not found." << std::endl;
    return;
  }

  MonthBitcoin::const_iterator firstMonthIt = yearIt->second.begin();
  MonthBitcoin::const_iterator lastMonthIt = getLastIterator(yearIt->second);
  if (input_month < firstMonthIt->first || input_month > lastMonthIt->first) {
    std::cerr << "Error: month " << input_month << " not in range ("
              << firstMonthIt->first << "~" << lastMonthIt->first << ")"
              << std::endl;
    return;
  }

  MonthBitcoin::const_iterator monthIt = yearIt->second.find(input_month);
  if (monthIt == yearIt->second.end()) {
    std::cerr << "Error: month " << input_month << " not found." << std::endl;
    return;
  }

  DayBitcoin::const_iterator firstDayIt = monthIt->second.begin();
  DayBitcoin::const_iterator lastDayIt = getLastIterator(monthIt->second);
  if (input_day < firstDayIt->first || input_day > lastDayIt->first) {
    std::cerr << "Error: day " << input_day << " not in range ("
              << firstDayIt->first << "~" << lastDayIt->first << ")"
              << std::endl;
    return;
  }
  DayBitcoin::const_iterator dayIt = monthIt->second.begin();
  DayBitcoin::const_iterator prevIt = monthIt->second.end();
  for (; dayIt != monthIt->second.end(); ++dayIt) {
    if (dayIt->first > input_day) {
      break;
    }
    prevIt = dayIt;
  }
  if (prevIt == monthIt->second.end()) {
    std::cerr << "Error: no available date before " << input_day << std::endl;
    return;
  }

  float result = input_value * prevIt->second;
  std::cout << input_year << "-" << input_month << "-" << input_day << " => "
            << input_value << " = " << result << std::endl;
}

int BitcoinExchange::validateInputFile(const YearBitcoin& bitcoin,
                                       const std::string& filename) {
  std::ifstream inputFile(filename);
  if (!inputFile) {
    std::cerr << "Error: could not open file." << std::endl;
    return ERROR;
  }

  std::string line;
  if (!std::getline(inputFile, line)) {
    std::cerr << "Error: unable to read the header line" << std::endl;
    return ERROR;
  }
  if (line != "date | value") {
    std::cerr << "Error: invalid header line" << std::endl;
    return ERROR;
  }
  while (std::getline(inputFile, line)) {
    processInputLine(bitcoin, line);
  }
  return SUCCESS;
}
