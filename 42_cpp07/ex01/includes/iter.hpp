#ifndef EX01_ITER_HPP_
#define EX01_ITER_HPP_

#include <cstddef>

template <typename T>
void iter(T* array, const std::size_t& len, void (*f)(T&)) {
  if (!array || !f) return;
  for (std::size_t i = 0; i < len; i++) {
    f(array[i]);
  }
}

template <typename T>
void iter(const T* array, const std::size_t& len, void (*f)(T const&)) {
  if (!array || !f) return;
  for (std::size_t i = 0; i < len; i++) {
    f(array[i]);
  }
}

template <typename U>
void test(U const & value) {
  std::cout << "Value: " << value << std::endl;
}

template <typename U>
void add(U& value) {
  value++;
}

#endif
