#include <iostream>
#include "ScalarConverter.hpp"

void testTitle(const std::string title);

void testConverterDouble(void) {
  testTitle("Test Convert Double");
  ScalarConverter::convert("42.0");
  std::cout << std::endl;
  ScalarConverter::convert("2147483647.0");
  std::cout << std::endl;
  ScalarConverter::convert("2147483648.0");
  std::cout << std::endl;
  ScalarConverter::convert("1.7976931348623157e+308");
  std::cout << std::endl;
  ScalarConverter::convert("2.2250738585072014e-308");
  std::cout << std::endl;
  ScalarConverter::convert("nan");
  std::cout << std::endl;
  ScalarConverter::convert("+inf");
  std::cout << std::endl;
  ScalarConverter::convert("-inf");
  std::cout << std::endl;
  testTitle("ERROR CASE");
  ScalarConverter::convert("\t");
  std::cout << std::endl;
  ScalarConverter::convert("\v");
  std::cout << std::endl;
  ScalarConverter::convert(" 2.0");
  std::cout << std::endl;
  ScalarConverter::convert("2.0 ");
  std::cout << std::endl;
  ScalarConverter::convert("1.7976931348623157e+309");
  std::cout << std::endl;
  ScalarConverter::convert("2.2250738585072014e-309");
  std::cout << std::endl;
}
