#ifndef EX02_ARRAY_HPP_
#define EX02_ARRAY_HPP_

template <typename T>
class Array {
 public:
  Array();
  Array(const unsigned int n);
  Array(const Array &other);
  Array<T> &operator=(const T &other);
  T &operator[](const unsigned int index) const;

  unsigned int size() const;
  ~Array();

 private:
  T *array_;
  unsigned int size_;
};

#include "Array.tpp"

#endif
