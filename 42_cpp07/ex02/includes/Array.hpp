#ifndef EX02_ARRAY_HPP_
#define EX02_ARRAY_HPP_

template <typename T>
class Array {
 public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  ~Array();
  Array<T> &operator=(const Array<T> &other);
  T &operator[](const unsigned int index) const;
  unsigned int size() const;

 private:
  T *array_;
  unsigned int size_;
};

#include "Array.tpp"

#endif
