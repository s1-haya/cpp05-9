#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

typedef std::map<int, float> DayBitcoin;
typedef std::map<int, DayBitcoin> MonthBitcoin;
typedef std::map<int, MonthBitcoin> YearBitcoin;

template <typename T>
typename T::const_iterator getLastIterator(const T& map) {
  typename T::const_iterator lastIt;
  for (typename T::const_iterator it = map.begin(); it !=map.end(); ++it) {
    lastIt = it;
  }
  return lastIt;
}

void addBitcoin(YearBitcoin& map, const std::string& line) {
  int year, month, day;
  float value;
  char dash;
  std::istringstream stream(line);
  stream >> year >> dash >> month >> dash >> day >> dash >> value;
  map[year][month][day] = value;
}

YearBitcoin getBitcoin() {
  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cerr << "Error: " << std::endl;
  }

  std::string line;
  if (!std::getline(file, line)) {
    std::cerr << "Error: Unable to read the header line" << std::endl;
  }
  YearBitcoin map;
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

void validateInputLine(const YearBitcoin& bitcoin) {
  int input_year = 2010;
  int input_month = 10;
  int input_day = 19;
  int input_value = 3;

  // ===== Year の範囲チェック =====
  YearBitcoin::const_iterator firstYearIt = bitcoin.begin();
  YearBitcoin::const_iterator lastYearIt = getLastIterator(bitcoin);

  std::cout << "Year " << input_year << ": (" << firstYearIt->first << "~" << lastYearIt->first << ")" << std::endl;

  if (input_year < firstYearIt->first || input_year > lastYearIt->first) {
    std::cerr << "Error: " << input_year << " not in range (" << firstYearIt->first << "~" << lastYearIt->first << ")" << std::endl;
    return;
  }

  YearBitcoin::const_iterator yearIt = bitcoin.find(input_year);
  if (yearIt == bitcoin.end()) {
    std::cerr << "Error: " << input_year << " not found." << std::endl;
    return;
  }

  // ===== Month の範囲チェック =====
  MonthBitcoin::const_iterator firstMonthIt = yearIt->second.begin();
  MonthBitcoin::const_iterator lastMonthIt = getLastIterator(yearIt->second);

  std::cout << "Month " << input_month << ": (" << firstMonthIt->first << "~" << lastMonthIt->first << ")" << std::endl;

  if (input_month < firstMonthIt->first || input_month > lastMonthIt->first) {
    std::cerr << "Error: " << input_month << " not in range (" << firstMonthIt->first << "~" << lastMonthIt->first << ")" << std::endl;
    return;
  }

  MonthBitcoin::const_iterator monthIt = yearIt->second.find(input_month);
  if (monthIt == yearIt->second.end()) {
    std::cerr << "Error: " << input_month << " not found." << std::endl;
    return;
  }

  // ===== Day の範囲チェック =====
  DayBitcoin::const_iterator firstDayIt = monthIt->second.begin();
  DayBitcoin::const_iterator lastDayIt = getLastIterator(monthIt->second);

  std::cout << "Day " << input_day << ": (" << firstDayIt->first << "~" << lastDayIt->first << ")" << std::endl;

  if (input_day < firstDayIt->first || input_day > lastDayIt->first) {
    std::cerr << "Error: " << input_day << " not in range (" << firstDayIt->first << "~" << lastDayIt->first << ")" << std::endl;
    return;
  }

  DayBitcoin::const_iterator dayIt = monthIt->second.find(input_day);
  if (dayIt == monthIt->second.end()) {
    std::cerr << "Error: " << input_day << " not found." << std::endl;
    return;
  }

  // ===== 計算・出力 =====
  float result = input_value * dayIt->second;
  std::cout << "Success: " << input_year << "-" << input_month << "-" << input_day
            << " => " << input_value << " = " << result << std::endl;
}

int main(void) {
  YearBitcoin map = getBitcoin();
  validateInputLine(map);
  // printBitcoin(map);
  return 0;
}
