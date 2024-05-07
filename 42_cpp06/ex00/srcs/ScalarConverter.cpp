#include "ScalarConverter.hpp"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>

#define CHAR_START 32
#define CHAR_END 126

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
  if (literal.find('.') != std::string::npos) return (false);
  std::stringstream stream(literal);
  int a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

bool isFloat(std::string literal) {
  if (literal[literal.length() - 1] == 'f')
    literal = literal.erase(literal.length() - 1);
  if (isInf(literal) || isNan(literal)) return (true);
  std::stringstream stream(literal);
  float a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

bool isDouble(std::string literal) {
  if (isInf(literal) || isNan(literal)) return (true);
  std::stringstream stream(literal);
  double a;

  stream >> a;
  if (!isSpace(literal[0]) && !stream.fail() && stream.eof()) return (true);
  return (false);
}

int getType(std::string literal) {
  if (isChar(literal))
    return (CHAR);
  else if (isInt(literal))
    return (INT);
  else if (isDouble(literal))
    return (DOUBLE);
  else if (isFloat(literal))
    return (FLOAT);
  return (INVALID);
}

void ScalarConverter::printError() {
  std::cout << "Char: impossible" << std::endl;
  std::cout << "Int: impossible" << std::endl;
  std::cout << "Float: impossible" << std::endl;
  std::cout << "Double: impossible" << std::endl;
}

void ScalarConverter::checkOverflowChar(int nb, bool isNan) {
  if (isNan || nb < static_cast<int>(std::numeric_limits<char>::min()) ||
      static_cast<int>(std::numeric_limits<char>::max()) < nb)
    std::cout << "Char: impossible" << std::endl;
  else
    ScalarConverter::printChar_(static_cast<char>(nb));
}

void ScalarConverter::checkOverflowInt(const std::string &literal) {
  int nb;
  std::stringstream ss(literal);

  ss >> nb;
  if (ss.fail())
    std::cout << "Int: impossible" << std::endl;
  else
    ScalarConverter::printInt_(nb);
}

void ScalarConverter::convert(std::string literal) {
  switch (getType(literal)) {
    case INVALID:
      printError();
      break;
    case CHAR: {
      char c = stringToChar_(literal);
      ScalarConverter::printChar_(c);
      ScalarConverter::printInt_(static_cast<int>(c));
      ScalarConverter::printFloat_(static_cast<float>(c));
      ScalarConverter::printDouble_(static_cast<double>(c));
      break;
    }
    case INT: {
      int nb = stringToInt_(literal);
      checkOverflowChar(nb, isNan(literal));
      ScalarConverter::printInt_(nb);
      ScalarConverter::printFloat_(static_cast<float>(nb));
      ScalarConverter::printDouble_(static_cast<double>(nb));
      break;
    }
    case FLOAT: {
      float nb = stringToFloat_(literal.erase(literal.length() - 1));
      checkOverflowChar(static_cast<int>(nb), isNan(literal));
      checkOverflowInt(literal);
      ScalarConverter::printFloat_(nb);
      ScalarConverter::printDouble_(static_cast<double>(nb));
      break;
    }
    case DOUBLE: {
      double nb = stringToDouble_(literal);
      if (nb < static_cast<double>(std::numeric_limits<float>::min()) ||
          static_cast<double>(std::numeric_limits<float>::max()) < nb) {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        if (nb == std::numeric_limits<double>::infinity())
          std::cout << "Float: +inff" << std::endl;
        else if (nb == -std::numeric_limits<double>::infinity())
          std::cout << "Float: -inff" << std::endl;
        else
          std::cout << "Float: impossible" << std::endl;
      } else {
        checkOverflowChar(static_cast<int>(nb), isNan(literal));
        checkOverflowInt(literal);
        ScalarConverter::printFloat_(nb);
      }
      ScalarConverter::printDouble_(nb);
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
  if (nb == std::numeric_limits<float>::infinity()) {
    std::cout << "Double: +inf";
  } else {
    std::cout << "Float: " << nb;
    if (nb != -std::numeric_limits<float>::infinity() &&
        (nb - std::floor(nb)) <= 0.0f)
      std::cout << ".0";
  }
  std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble_(const double nb) {
  if (nb == std::numeric_limits<double>::infinity()) {
    std::cout << "Double: +inf";
  } else {
    std::cout << "Double: " << nb;
    if (nb != -std::numeric_limits<double>::infinity() &&
        (nb - std::floor(nb)) <= 0.0f)
      std::cout << ".0";
  }
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
