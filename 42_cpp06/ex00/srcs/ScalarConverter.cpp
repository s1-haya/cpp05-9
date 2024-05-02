#include "ScalarConverter.hpp"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>

#define CHAR_START 32
#define CHAR_END 126

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return (*this);
}
ScalarConverter::~ScalarConverter() {}

bool isNan(std::string literal) { return (literal == "nan"); }

bool isInf(std::string literal) {
  return (literal == "-inf" || literal == "+inf");
}

int isSpace(int c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
          c == '\r');
}

bool isChar(std::string literal) {
  return (literal.size() == 1 && (!('0' <= literal[0] && literal[0] <= '9')));
}

bool isInt(std::string literal) {
  std::stringstream stream(literal);
  int a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

bool isDouble(std::string literal) {
  if (isInf(literal) || isNan(literal)) return (true);
  if (literal.find('.') == std::string::npos) return (false);
  std::stringstream stream(literal);
  double a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

bool isFloat(std::string literal) {
  if (literal[literal.length() - 1] == 'f')
    literal = literal.erase(literal.length() - 1);
  if (isInf(literal) || isNan(literal)) return (true);
  if (literal.find('.') == std::string::npos) return (false);
  std::stringstream stream(literal);
  float a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

int getType(std::string literal) {
  int type = INVALID;
  if (isChar(literal))
    type = CHAR;
  else if (isDouble(literal))
    type = DOUBLE;
  else if (isFloat(literal))
    type = FLOAT;
  else if (isInt(literal))
    type = INT;
  return (type);
}

void ScalarConverter::convert(std::string literal) {
  int type = getType(literal);
  switch (type) {
    case INVALID:
      std::cerr << "Invalid input!" << std::endl;
      break;
    case CHAR: {
      char c = stringToChar_(literal);
      printChar_(c);
      printInt_(static_cast<int>(c));
      printFloat_(static_cast<float>(c));
      printDouble_(static_cast<double>(c));
      break;
    }
    case INT: {
      int nb = stringToInt_(literal);
      printChar_(static_cast<char>(nb));
      printInt_(nb);
      printFloat_(static_cast<float>(nb));
      printDouble_(static_cast<double>(nb));
      break;
    }
    case FLOAT: {
      float nb = stringToFloat_(literal.erase(literal.length() - 1));
      if (isNan(literal)) {
        std::cerr << "Char: impossible" << std::endl;
        std::cerr << "Int: impossible" << std::endl;
      } else {
        printChar_(static_cast<char>(nb));
        printInt_(static_cast<int>(nb));
      }
      printFloat_(nb);
      printDouble_(static_cast<double>(nb));
      break;
    }
    case DOUBLE: {
      double nb = stringToDouble_(literal);
      if (isNan(literal)) {
        std::cerr << "Char: impossible" << std::endl;
        std::cerr << "Int: impossible" << std::endl;
      } else {
        printChar_(static_cast<char>(nb));
        printInt_(static_cast<int>(nb));
      }
      printFloat_(static_cast<float>(nb));
      printDouble_(nb);
      break;
    }
  }
}

void ScalarConverter::printChar_(const char c) {
  std::cout << "Char: ";
  if (c < CHAR_START || CHAR_END < c)
    std::cerr << "Non displayable";
  else
    std::cout << "'" << c << "'";
  std::cout << std::endl;
}

void ScalarConverter::printInt_(const int nb) {
  std::cout << "Int: " << nb << std::endl;
}

void ScalarConverter::printFloat_(const float nb) {
  std::cout << "Float: " << nb;
  if (nb != std::numeric_limits<float>::infinity() &&
      nb != -std::numeric_limits<float>::infinity() && (nb - std::floor(nb)) <= 0.0f)
    std::cout << ".0";
  std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble_(const double nb) {
  std::cout << "Double: " << nb;
  if (nb != std::numeric_limits<double>::infinity() &&
      nb != -std::numeric_limits<double>::infinity() &&
      (nb - std::floor(nb)) <= 0.0f)
    std::cout << ".0";
  std::cout << std::endl;
}

char ScalarConverter::stringToChar_(std::string const &literal) {
  return (literal[0]);
}

int ScalarConverter::stringToInt_(std::string const &literal) {
  int nb;
  std::istringstream stream(literal);
  stream >> nb;
  return (nb);
}

float ScalarConverter::stringToFloat_(std::string const &literal) {
  float nb;
  if (isNan(literal))
    nb = std::numeric_limits<float>::quiet_NaN();
  else if (isInf(literal)) {
    if (literal == "+inf")
      nb = std::numeric_limits<float>::infinity();
    else
      nb = -std::numeric_limits<float>::infinity();
  } else {
    std::istringstream stream(literal);
    stream >> nb;
  }
  return (nb);
}

double ScalarConverter::stringToDouble_(std::string const &literal) {
  double nb;
  if (isNan(literal))
    nb = std::numeric_limits<double>::quiet_NaN();
  else if (isInf(literal)) {
    if (literal == "+inf")
      nb = std::numeric_limits<double>::infinity();
    else
      nb = -std::numeric_limits<double>::infinity();
  } else {
    std::istringstream stream(literal);
    stream >> nb;
  }
  return (nb);
}
