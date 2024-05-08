#include "Array.hpp"
#include "testAssert.hpp"
#include <cassert>

void testTitle(const std::string title);

void testArray(void) {
  testTitle("Template Array Test");
  testTitle("Default Constructor");
  try {
    Array<char *> arrayCharPtr;
    // don't implement testIsNULL because throw in Array<T>::operator[];
    testIsNULL(arrayCharPtr[0]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Array<char *> arrayCharPtr(4);
    for (size_t i = 0; i < 4; i++) {
      	std::cout << "memory: " << &(arrayCharPtr[i]) << std::endl;
    }
    assert(arrayCharPtr[0] == NULL); 
    // std::cout << arrayCharPtr[0] << std::endl;
    testIsNULL(arrayCharPtr[0]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  testTitle("Copy Constructor & Assignment operator");
  try {
    unsigned int size = 10;
    Array<int> arrayInt(size);
    for (unsigned int i = 0; i < size; i++) {
      arrayInt[i] = i;
    }
    Array<int> copyArrayInt(arrayInt);
    testNotAssert(&arrayInt, &copyArrayInt);
    for (unsigned int i = 0; i < size; i++) {
      testNotAssert(&(arrayInt[i]), &(copyArrayInt[i]));
    }
    Array<int> assignmentArrayInt;
    assignmentArrayInt = arrayInt;
    for (unsigned int i = 0; i < size; i++) {
      testNotAssert(&(arrayInt[i]), &(assignmentArrayInt[i]));
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
