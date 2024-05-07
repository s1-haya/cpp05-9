#include <iostream>
#include "ScalarConverter.hpp"

void testTitle(const std::string title);

void testConverterFloat(void) {
  testTitle("Test Convert Float");
  ScalarConverter::convert("42.0f");
  std::cout << std::endl;
  ScalarConverter::convert("3.40282347e+38F");
  std::cout << std::endl;
  ScalarConverter::convert("1.17549435e-38F");
  std::cout << std::endl;
  ScalarConverter::convert("nanf");
  std::cout << std::endl;
  ScalarConverter::convert("+inff");
  std::cout << std::endl;
  ScalarConverter::convert("-inff");
  std::cout << std::endl;
  testTitle("ERROR CASE");
  ScalarConverter::convert("\t");
  std::cout << std::endl;
  ScalarConverter::convert("\v");
  std::cout << std::endl;
  ScalarConverter::convert(" 2.0f");
  std::cout << std::endl;
  ScalarConverter::convert("2.0f ");
  std::cout << std::endl;
  ScalarConverter::convert("-21474836480.f");
  std::cout << std::endl;
  ScalarConverter::convert("-21474836480f");
  std::cout << std::endl;
  ScalarConverter::convert("3.40282347e+40F");
  std::cout << std::endl;
  ScalarConverter::convert("1.17549435e-40F");
  std::cout << std::endl;
}
