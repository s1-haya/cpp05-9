#include <iostream>

int main(void) {
  int *a = new int();
  std::cout << a << std::endl;
  std::cout << *a << std::endl;

  int *b = new int[2];
  std::cout << &(b[0]) << std::endl;
  std::cout << &(b[1]) << std::endl;
  // std::cout << a[0] << std::endl;
}
