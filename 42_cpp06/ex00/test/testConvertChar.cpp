#include "ScalarConverter.hpp"
#include <iostream>

void testTitle(const std::string title);

void testConverterChar(void) {
  testTitle("Test Convert Char");
  ScalarConverter::convert("!");
  std::cout << std::endl;
  ScalarConverter::convert("~");
  std::cout << std::endl;
  ScalarConverter::convert(" ");
  std::cout << std::endl;
  ScalarConverter::convert("3");
  std::cout << std::endl;
  testTitle("ERROR CASE");
  ScalarConverter::convert("\t");
  std::cout << std::endl;
  ScalarConverter::convert("\v");
  std::cout << std::endl;
  ScalarConverter::convert(" a");
  std::cout << std::endl;
  ScalarConverter::convert("a ");
  std::cout << std::endl;
}
