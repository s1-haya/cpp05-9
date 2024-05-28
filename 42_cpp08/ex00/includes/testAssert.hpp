#ifndef TEST_ASSERT_HPP_
#define TEST_ASSERT_HPP_

#include <iostream>
#include "color.hpp"

template <typename T>
void testAssert(const T& expect, const T& output) {
  if (expect == output) {
    std::cout << color::GREEN << "OK" << color::DEFAULT <<  std::endl;
  } else {
    std::cout << color::RED << "KO" << color::DEFAULT << std::endl;
    std::cout << "Except: " << expect << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

template <typename T>
void testNotAssert(const T& expect, const T& output) {
  if (expect != output) {
    std::cout << color::GREEN << "OK" << color::DEFAULT <<  std::endl;
  } else {
    std::cout << color::RED << "KO" << color::DEFAULT << std::endl;
    std::cout << "Except: " << expect << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

template <typename T>
void testIsNULL(const T& output) {
  if (NULL == output) {
    std::cout << color::GREEN << "OK" << color::DEFAULT <<  std::endl;
  } else {
    std::cout << color::RED << "KO" << color::DEFAULT << std::endl;
    std::cout << "Except: "
              << "NULL" << std::endl;
    std::cout << "Output: " << output << std::endl;
  }
}

#endif
