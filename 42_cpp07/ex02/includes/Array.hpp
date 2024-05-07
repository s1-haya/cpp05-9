#ifndef EX00_WHATEVER_HPP_
#define EX00_WHATEVER_HPP_

template <typename T>
class Array {
  public:
    Array();
    Array(const unsigned int n);
    // Array(Array const& other);
    // Array operaotor=(Array const& other);
    unsigned int getN() const;
    ~Array();
  private:
    T *array_;
    unsigned int n_;
};

template <typename T>
Array<T>::Array() {
  array_ = new T[0];
  n_ = 0;
}

template <typename T>
Array<T>::Array(const unsigned int n) {
  array_ = new T[n];
  n_ = n;
}

template <typename T>
Array<T>::~Array() {
  delete [] array_;
}

template <typename T>
unsigned int Array<T>::getN() const {
  return (this->n_);
}

#endif
