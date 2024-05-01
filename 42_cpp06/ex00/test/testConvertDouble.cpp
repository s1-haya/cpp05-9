#include <iostream>
#include "ScalarConverter.hpp"

void testTitle(const std::string title);

void testConverterDouble(void) {
  testTitle("Test Convert Double");
  ScalarConverter::convert("42.0");
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
}
