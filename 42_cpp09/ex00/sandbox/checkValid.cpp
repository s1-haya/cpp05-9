#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

typedef std::map<int, double> DayBitcoin;
typedef std::map<int, DayBitcoin> MonthBitcoin;
typedef std::map<int, MonthBitcoin> YearBitcoin;
void addBitcoin(YearBitcoin& map, const std::string& line);
void printBitcoin(const YearBitcoin& Bitcoin);

YearBitcoin getBitcoin();

bool checkValid(const std::string& line) {
  size_t separatorPos = line.find(" | ");
  if (separatorPos == std::string::npos) {
    std::cout << "Error: not | " << std::endl;
    return false;
  }

  std::string dateStr = line.substr(0, separatorPos);
  std::string valueStr = line.substr(separatorPos + 3);

  if (dateStr.front() == ' ' || dateStr.back() == ' ' ||
      valueStr.front() == ' ' || valueStr.back() == ' ') {
    std::cout << "Error: space front or back " << std::endl;
    return false;
  }

  if (dateStr.length() != 10) {
    std::cout << "Error: not YYYY-MM-DD " << std::endl;
    return false;
  }

  std::istringstream dateStream(dateStr);
  int year, month, day;
  char dash1, dash2;

  if (!(dateStream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' ||
      dash2 != '-') {
    std::cout << "Error: not - " << std::endl;
    return false;
  }

  if (year == 2009 && month == 1 && day < 2) {
  }
  if (!(2009 <= year && year <= 2022)) {
    std::cout << "Error: not Year " << std::endl;
    return false;
  } else if (!(1 <= month && month <= 12) || (year == 2022 && month > 3)) {
    std::cout << "Error: not Month " << std::endl;
    return false;
  } else if (!(1 <= day && day <= 31) || (year == 2022 && day > 29) ||
             (year == 2009 && month == 1 && day == 1)) {
    std::cout << "Error: not Day " << std::endl;
    return false;
  }

  std::istringstream valueStream(valueStr);
  if (valueStr == "-0") {
    std::cout << "Error: -0 is not a valid value" << std::endl;
    return false;
  }
  double value;
  if (!(valueStream >> value)) {
    std::cout << "Error: not Float type value " << std::endl;
    return false;
  }

  if ((!(0.0 <= value && value <= 1000))) {
    std::cout << "Error: not range from 0 to 1000 " << std::endl;
    return false;
  }

  YearBitcoin Bitcoin = getBitcoin();
  for (YearBitcoin::const_iterator yearIt = Bitcoin.begin();
       yearIt != Bitcoin.end(); ++yearIt) {
    if (yearIt->first == year) {
      std::cout << year << dash1;
      for (MonthBitcoin::const_iterator monthIt = yearIt->second.begin();
           monthIt != yearIt->second.end(); ++monthIt) {
        if (monthIt->first == month) {
          std::cout << month << dash2;
          for (DayBitcoin::const_iterator dayIt = monthIt->second.begin();
               dayIt != monthIt->second.end(); ++dayIt) {
            if (dayIt->first > day) {
              dayIt--;
              std::cout << day << " => " << value << " = "
                        << dayIt->second * value << std::endl;
              dayIt++;
              break;
            }
          }
        }
      }
    }
  }
  return true;
}

int main(void) {
  std::cout << "Success" << std::endl;
  checkValid("2011-01-03 | 3");

  std::cout << std::endl;

  std::cout << "Error: not 'value | Bitcoin'" << std::endl;
  checkValid(" 2011-01-03 - 3");
  checkValid(" 2011-01-03 | 3");
  checkValid("2011-01-03 | 3 ");
  checkValid("2011-01-03 |  3 ");
  checkValid("2011-01-03  | 3");
  checkValid("2011-01- 03 | 3");
  checkValid("2011-01| 03 | 3");
  checkValid("2011-01|03 | 3");

  std::cout << std::endl;

  std::cout << "Error: Invalid date!" << std::endl;
  checkValid("2000-01-03 | 3");
  checkValid("2014-13-03 | 3");
  checkValid("2014-12-89 | 3");
  checkValid("2022-c3-30 | 3");
  checkValid("2022-03-t | 3");
  checkValid("2022-03-tt | 3");
  checkValid("2c23-03-01 | 3");
  checkValid("2009-03-00 | 3");
  checkValid("2022-03-30 | 0");
  checkValid("2009-01-01 | 0");
  checkValid("2022-03-31 | 0");

  std::cout << std::endl;

  std::cout << "Success: value" << std::endl;
  checkValid("2022-03-28 | 0");
  checkValid("2022-03-28 | 1");
  checkValid("2022-03-28 | -0");
  checkValid("2022-03-29 | 1000");
  std::cout << "Error: Invalid value!" << std::endl;
  checkValid("2022-03-30 | -1");
  checkValid("2022-03-30 | -0.1");
  checkValid("2022-03-30 | 1001");
  checkValid("2022-03-29 | --0");
  checkValid("2022-03-29 | a");
  checkValid("2022-03-29 | 3.0a");
  return 0;
}
