#include <list>

#include "easyfind.hpp"
#include "testAssert.hpp"

void testTitle(const std::string title);

void testListInt() {
  testTitle("Test List");
  std::list<int> v;
  for (size_t i = 0; i < 5; i++) v.push_back(i);

  std::cout << "v = ";
  for (std::list<int>::iterator i = v.begin(), e = v.end(); i != e; i++) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;

  try {
    testAssert(easyfind(v, 1), 1);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    easyfind(v, 42);
  } catch (const std::exception &e) {
    std::cout << color::GREEN << "OK" << color::DEFAULT << std::endl;
    std::cerr << e.what() << std::endl;
  }

  testTitle("Test Const List");
  const std::list<int> cv = v;
  try {
    testAssert(easyfind(cv, 1), 1);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    easyfind(cv, 42);
  } catch (const std::exception &e) {
    std::cout << color::GREEN << "OK" << color::DEFAULT << std::endl;
    std::cerr << e.what() << std::endl;
  }
}
