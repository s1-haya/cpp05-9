#ifndef EX00_WHATEVER_HPP_
#define EX00_WHATEVER_HPP_

#include <cstdint>
#include <iostream>

template <typename T>
class Array {
 public:
  Array();
  Array(const unsigned int n);
  Array(const Array &other);
  const T &operator=(const T &other);
  T &operator[](const unsigned int index) const;

  unsigned int size() const;
  ~Array();

 private:
  T *array_;
  unsigned int size_;
};

#include "Array.tpp"

#endif
