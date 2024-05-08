#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : array_(new T[0]), size_(0){};

template <typename T>
Array<T>::Array(const unsigned int n) : array_(new T[n]), size_(n){};

template <typename T>
Array<T>::~Array() {
  delete[] array_;
};

template <typename T>
unsigned int Array<T>::size() const {
  return (this->size_);
};

template <typename T>
Array<T>::Array(const Array &other)
    : array_(new T[other.size_]), size_(other.size_) {
  for (unsigned int i = 0; i < other.size_; i++) {
    array_[i] = other.array_[i];
  }
};

template <typename T>
Array<T> &Array<T>::operator=(const T &other) {
  std::cout << "assignment" << std::endl;
  if (this != &other) {
    delete[] this->array_;
    this->array_ = new T[other.size_];
    this->size_ = other.size_;
    for (unsigned int i = 0; i < other.size_; i++) {
      this->array_[i] = other[i];
    }
  }
  return (*this);
};

template <typename T>
T &Array<T>::operator[](const unsigned int index) const {
  if (index >= this->size_) {
    throw(std::out_of_range("Index out of range"));
  }
  return (this->array_[index]);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
  unsigned int size = array.size();
  for (unsigned int i = 0; i < size; i++) {
    os << "value[" << i << "]: " << array[i] << std::endl;
  }
  return (os);
};
