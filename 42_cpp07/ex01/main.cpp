#include <iostream>

#include "iter.hpp"

struct Data {
  int num;
  std::string name;
};

int main(void) {
  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  iter(A, sizeof(A) / sizeof(A[0]), &test);
  const char *B[5] = {"az", "bz", "cz", "dz", "ez"};
  iter(B, sizeof(B) / sizeof(B[0]), &test);
  return (0);
}
