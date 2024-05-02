#include <iostream>
#include "ScalarConverter.hpp"

void testTitle(const std::string title);

void testConverterInt(void) {
  testTitle("Test Convert Int");
  ScalarConverter::convert("42");
  std::cout << std::endl;
  ScalarConverter::convert("2147483647");
  std::cout << std::endl;
  ScalarConverter::convert("-2147483648");
  std::cout << std::endl;
  testTitle("ERROR CASE");
  ScalarConverter::convert("\t");
  std::cout << std::endl;
  ScalarConverter::convert("\v");
  std::cout << std::endl;
  ScalarConverter::convert(" 2");
  std::cout << std::endl;
  ScalarConverter::convert("2 ");
  std::cout << std::endl;
  ScalarConverter::convert("2147483648");
  std::cout << std::endl;
  ScalarConverter::convert("-2147483649");
  std::cout << std::endl;
}
