#include <cassert>
#include <cstdlib>
#include <iostream>

#include "Span.hpp"

void testTitle(const std::string title);

void testSpan(void) {
  srand(time(NULL));
  try {
    Span sp = Span(5);
    sp.printStorage();

    sp.addNumber(2147483647);
    sp.printStorage();
    sp.addNumber(-2147483648);
    sp.printStorage();
    sp.addNumber(2147483647);
    sp.printStorage();
    sp.addNumber(-2147483648);
    sp.addNumber(-2147483648);
    // sp.addNumber(-2147483648);
    // sp.addNumber(-2147483648);

    std::cout << "shortestSpan() = " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan() = " << sp.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Span sp = Span(3);
    sp.addRandomNumbers(3, INT_MIN + 1, 0);
    sp.printStorage();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    sp.addNumber(42);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  Span sp0 = Span(0);
  sp0.printStorage();
  try {
    std::cout << sp0.shortestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  Span sp1 = Span(1);
  sp1.addNumber(20);
  sp1.printStorage();
  try {
    std::cout << sp1.shortestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  << std::endl;
  Span sp2 = Span(100);
  sp2.addRandomNumbers(100);
  sp2.printStorage();
  try {
    //		sp2.addNumber(1);
    std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
    std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
