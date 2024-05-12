#include <cassert>

#include "Array.hpp"
#include "testAssert.hpp"

void testTitle(const std::string title);

void testArray(void) {
  testTitle("Template Array Test");
  try {
    testTitle(
        "Whether the value calling the default constructor is an empty "
        "array\n- Expect: index out of range");
    Array<char*> arrayCharPtr;
    (void)arrayCharPtr[0];
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    testTitle(
        "Whether the value calling the default constructor is an empty "
        "array\n- Expect: index out of range");
    Array<int> arrayInt(2);
    arrayInt[0] = 42;
    const Array<int> arrayCopyInt(arrayInt);
    std::cout << "0: " << arrayCopyInt[0] << std::endl;
    // arrayCopyInt[0] = 0;
    // const Array<int> arrayInt(4);
    // (void)arrayInt[0];
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    testTitle(
        "Whether memory is allocated according to the number of elements\n- "
        "Expect: allocate 8byte memory");
    Array<char*> arrayCharPtr(4);
    for (size_t i = 0; i < 4; i++) {
      std::cout << "init memory: " << &(arrayCharPtr[i]) << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    testTitle(
        "Whether memory is not allocated according to the number of elements "
        "equals zero\n- Expect: index out of range and not double free");
    Array<char*> arrayCharPtr(0);
    (void)arrayCharPtr;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  testTitle("Copy Constructor & Assignment operator");
  try {
    unsigned int size = 10;
    Array<int> arrayInt(size);
    for (size_t i = 0; i < size; i++) {
      arrayInt[i] = i;
    }
    Array<int> copyArrayInt(arrayInt);
    testTitle(
        "Whether the Copy Constructor Array<T> is a different pointer\n- "
        "Expect: OK");
    testNotAssert(&arrayInt, &copyArrayInt);
    for (size_t i = 0; i < size; i++) {
      testNotAssert(&(arrayInt[i]), &(copyArrayInt[i]));
    }
    testTitle(
        "Whether the Copy Constructor Array<T> is a same value\n- Expect: OK");
    for (size_t i = 0; i < size; i++) {
      testAssert(arrayInt[i], copyArrayInt[i]);
    }
    testTitle(
        "Whether the Assignment Array<T> is a different pointer\n- Expect: OK");
    Array<int> assignmentArrayInt;
    assignmentArrayInt = arrayInt;
    for (size_t i = 0; i < size; i++) {
      testNotAssert(&(arrayInt[i]), &(assignmentArrayInt[i]));
    }
    testTitle("Whether the Assignment Array<T> is a same value\n- Expect: OK");
    for (size_t i = 0; i < size; i++) {
      testAssert(arrayInt[i], assignmentArrayInt[i]);
    }
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
