#ifndef EX01_ITER_HPP_
#define EX01_ITER_HPP_

#include <cstddef>

template <typename T>
void iter(T* array, std::size_t len, void (*f)(T&)) {
  if (!array || !f) return;
  for (std::size_t i = 0; i < len; i++) {
    f(array[i]);
  }
}

template <typename U>
void test(U& value) {
  std::cout << "Value: " << value << std::endl;
}

#endif
