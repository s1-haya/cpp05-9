#ifndef TEST_ASSERT_HPP_
#define TEST_ASSERT_HPP_

#include <iostream>
#include "color.hpp"

template <typename T>
void testAssert(const T& expect, const T& output) {
  if (expect == output) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
  } else {
    std::cout << RED << "KO" << DEFAULT << std::endl;
    std::cout << "Except: " << expect << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

template <typename T>
void testNotAssert(const T& expect, const T& output) {
  if (expect != output) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
  } else {
    std::cout << RED << "KO" << DEFAULT << std::endl;
    std::cout << "Except: " << expect << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

template <typename T>
void testIsNULL(const T& output) {
  if (NULL == output) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
  } else {
    std::cout << RED << "KO" << DEFAULT << std::endl;
    std::cout << "Except: "
              << "NULL" << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

#endif
