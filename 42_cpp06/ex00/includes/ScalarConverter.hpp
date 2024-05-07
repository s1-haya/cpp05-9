#ifndef EX00_SCALARCONVERTER_HPP_
#define EX00_SCALARCONVERTER_HPP_

#include <string>

enum types { INVALID, CHAR, INT, FLOAT, DOUBLE };

class ScalarConverter {
 public:
  static void convert(std::string literal);

 private:
  static void printChar_(const char c);
  static void printInt_(const int nb);
  static void printFloat_(const float nb);
  static void printDouble_(const double nb);
  static void printError();

  static char stringToChar_(std::string const& literal);
  static int stringToInt_(std::string const& literal);
  static float stringToFloat_(std::string const& literal);
  static double stringToDouble_(std::string const& literal);

  static void checkOverflowChar(int nb, bool isNan);
  static void checkOverflowInt(const std::string& literal);

  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);
  ~ScalarConverter();
};

#endif
