#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Span.hpp"
#include "testAssert.hpp"

void testTitle(const std::string title);

void testSpan(void) {
  srand(time(NULL));
  try {
    testTitle("Min Shortest and Max Longest in Span Class");
    Span sp3 = Span(3);
    sp3.printStorage();
    sp3.addNumber(2147483647);
    sp3.addNumber(-2147483648);
    sp3.addNumber(2147483647);
    sp3.printStorage();
    size_t expect_short = 0;
    testAssert(expect_short, sp3.shortestSpan());
    size_t expect_long = 2147483647 + 2147483648;
    testAssert(expect_long, sp3.longestSpan());
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    testTitle("Any attempt to add a new element if there are already N elements stored should throw an exception");
    Span sp1(1);
    sp1.addNumber(1);
    sp1.addNumber(2);
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle(
        "ShortestSpan: this storage are no numbers stored, throw an exception");
    Span sp0(0);
    std::cout << sp0.shortestSpan() << std::endl;
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp0.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle(
        "LongestSpan: this storage are no numbers stored, throw an exception");
    Span sp0(0);
    std::cout << sp0.longestSpan() << std::endl;
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp0.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle("ShortestSpan: this storage is only one, throw an exception");
    Span sp1(1);
    sp1.addNumber(42);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp1.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle("LongestSpan: this storage is only one, throw an exception");
    Span sp1(1);
    sp1.addNumber(42);
    std::cout << sp1.longestSpan() << std::endl;
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp1.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    Span sp2 = Span(10000);
    testTitle("Storage 10000");
    size_t storage = 10000;
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testNotAssert(storage, sp2.getStorageSize());
    sp2.addRandomNumbers(storage, 1, 1);
    testAssert(storage, sp2.getStorageSize());
    // sp2.addRandomNumbers(storage, INT_MIN, INT_MIN);
    // sp2.addRandomNumbers(storage, INT_MAX, INT_MAX);
    // error: implicit conversion from 'long' to 'int' changes value from
    // -2147483649 to 2147483647 sp2.addRandomNumbers(storage, -2147483649,
    // INT_MIN); error: implicit conversion from 'long' to 'int' changes value
    // from 2147483648 to -2147483648 sp2.addRandomNumbers(storage, 2147483648,
    // INT_MAX); sp2.printStorage();
    //		sp2.addNumber(1);
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
    std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
