#include <cassert>
#include <cstdlib>
#include <climits>
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
    testTitle("AddRandomNumbers: throw an exception when min is greator than max");
    Span sp10(10);
    sp10.addRandomNumbers(10, 42, -42);
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp10.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle("AddRandomNumbers: throw an exception when N is greator than storage max size");
    Span sp10(10);
    sp10.addRandomNumbers(20, 1, 42);
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp10.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    testTitle("AddRandomNumbers: throw an exception when range from min to max is greator than RANDOM_MAX");
    Span sp10(10);
    sp10.addRandomNumbers(10, INT_MIN, INT_MAX);
    std::cout << RED << "KO" << DEFAULT <<  std::endl;
    sp10.printStorage();
  } catch (const std::exception& e) {
    std::cout << GREEN << "OK" << DEFAULT <<  std::endl;
    std::cerr << e.what() << std::endl;
  }

  try {
    Span sp2 = Span(10000);
    testTitle("Storage max size is 10000.");
    size_t storage = 10000;
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testNotAssert(storage, sp2.getStorageSize());
    sp2.addRandomNumbers(storage, 1, 100);
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testAssert(storage, sp2.getStorageSize());
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Span sp2 = Span(1000000);
    testTitle("Storage max size is 1000000.");
    size_t storage = 1000000;
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testNotAssert(storage, sp2.getStorageSize());
    sp2.addRandomNumbers(storage, 1, 100);
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testAssert(storage, sp2.getStorageSize());
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Span sp2 = Span(10000000);
    testTitle("Storage max size is 10000000.");
    size_t storage = 10000000;
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testNotAssert(storage, sp2.getStorageSize());
    sp2.addRandomNumbers(storage, 1, 100);
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testAssert(storage, sp2.getStorageSize());
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Span sp2 = Span(100000000);
    testTitle("Storage max size is 100000000.");
    size_t storage = 100000000;
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testNotAssert(storage, sp2.getStorageSize());
    sp2.addRandomNumbers(storage, 1, 100);
    std::cout << "storage_size: " << sp2.getStorageSize() << std::endl;
    testAssert(storage, sp2.getStorageSize());
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
