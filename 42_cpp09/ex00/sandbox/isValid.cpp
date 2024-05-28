#include <iostream>
#include <map>
#include <sstream>
#include <string>

bool isValid(const std::string& line) {
  size_t separatorPos = line.find(" | ");
  if (separatorPos == std::string::npos) {
    std::cerr << "Error: not | " << std::endl;
    return false;
  }

  std::string dateStr = line.substr(0, separatorPos);
  std::string valueStr = line.substr(separatorPos + 3);

  if (dateStr.front() == ' ' || dateStr.back() == ' ' ||
      valueStr.front() == ' ' || valueStr.back() == ' ') {
    std::cerr << "Error: space front or back " << std::endl;
    return false;
  }

  if (dateStr.length() != 10) {
    std::cerr << "Error: not YYYY-MM-DD " << std::endl;
    return false;
  }

  std::istringstream dateStream(dateStr);
  int year, month, day;
  char dash1, dash2;

  if (!(dateStream >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' ||
      dash2 != '-') {
    std::cerr << "Error: not - " << std::endl;
    return false;
  }

  if (!(2009 <= year && year <= 2022)) {
    std::cerr << "Error: not Year " << std::endl;
    return false;
  } else if (!(1 <= month && month <= 12)) {
    std::cerr << "Error: not Month " << std::endl;
    return false;
  } else if (!(1 <= day && day <= 31)) {
    std::cerr << "Error: not Day " << std::endl;
    return false;
  }

  std::istringstream valueStream(valueStr);
  float value;
  if (!(valueStream >> value)) {
    std::cerr << "Error: not Float type value " << std::endl;
    return false;
  }

  if ((!(0.0 <= value && value <= 1000))) {
    std::cerr << "Error: not range from 0 to 1000 " << std::endl;
    return false;
  }

  std::cout << "GOOOD " << std::endl;
  return true;
}

int main(void) {
  std::cout << "Success" << std::endl;
  isValid("2011-01-03 | 3");

  std::cout << std::endl;

  std::cout << "Error: not 'value | data'" << std::endl;
  isValid(" 2011-01-03 - 3");
  isValid(" 2011-01-03 | 3");
  isValid("2011-01-03 | 3 ");
  isValid("2011-01-03 |  3 ");
  isValid("2011-01-03  | 3");
  isValid("2011-01- 03 | 3");
  isValid("2011-01| 03 | 3");
  isValid("2011-01|03 | 3");

  std::cout << std::endl;

  std::cout << "Error: Invalid date!" << std::endl;
  isValid("2000-01-03 | 3");
  isValid("2014-13-03 | 3");
  isValid("2014-12-89 | 3");
  isValid("2022-c3-30 | 3");
  isValid("2022-03-t | 3");
  isValid("2022-03-tt | 3");
  isValid("2c23-03-01 | 3");
  isValid("2009-03-00 | 3");

  std::cout << std::endl;

  std::cout << "Success: value" << std::endl;
  isValid("2022-03-30 | 0");
  isValid("2022-03-30 | -0");
  isValid("2022-03-30 | 1000");
  std::cout << "Error: Invalid value!" << std::endl;
  isValid("2022-03-30 | -1");
  isValid("2022-03-30 | -0.1");
  isValid("2022-03-30 | 1001");
  return 0;
}
