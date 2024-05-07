#ifndef EX00_WHATEVER_HPP_
#define EX00_WHATEVER_HPP_

#include <cstdint>
#include <iostream>

template <typename T>
class Array {
 public:
  Array();
  Array(const unsigned int n);
  Array(Array const &other);
  Array<T> &operator=(Array<T> const &other);

  unsigned int getSize() const;
  const T &getValueInArray(size_t index) const;
  void setValueInArray(const T &value, std::size_t index);
  ~Array();

 private:
  T *array_;
  unsigned int size_;
};

template <typename T>
Array<T>::Array() {
  array_ = new T[0];
  size_ = 0;
};

template <typename T>
Array<T>::Array(const unsigned int n) {
  array_ = new T[n];
  size_ = n;
};

template <typename T>
Array<T>::~Array() {
  delete[] array_;
};

template <typename T>
unsigned int Array<T>::getSize() const {
  return (this->size_);
};

template <typename T>
Array<T>::Array(Array const &other) {
  for (size_t i = 0; i < other.size_; i++) {
    this->setValueInArray(other.getValueInArray(i), i);
  }
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &other) {
  if (this != &other) {
    for (std::size_t i = 0; i < size_; i++) {
      this->setValueInArray(other.getValueInArray(i), i);
    }
  }
  return (*this);
}

template <typename T>
const T &Array<T>::getValueInArray(size_t index) const {
  if (!(index < this->size_)) {
    static const std::string emptyString;
    std::cerr << "Error: The upper limit is exceed." << std::endl;
    return (this->array_[0]);
  }
  return (this->array_[index]);
}

template <typename T>
void Array<T>::setValueInArray(const T &value, size_t index) {
  if (!(index < this->size_)) {
    std::cerr << "Error: " << value << " could not be registered because the "
              << index << " index exceeded the upper limit of ideas."
              << std::endl;
    return;
  }
  this->array_[index] = value;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
  size_t size = array.getSize();
  for (std::size_t i = 0; i < size; i++) {
    os << "value[" << i << "]: " << array.getValueInArray(i) << std::endl;
  }
  return (os);
}

#endif
