#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
  *this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
  if (this != &other) {
    this->c = other.c;
  }
  return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
void MutantStack<T>::push(const T &value) {
  this->stack.push(value);
  this->c.push_back(value);
}

template <typename T>
void MutantStack<T>::pop() {
  this->stack.pop();
  this->c.pop_back();
}

template <typename T>
T &MutantStack<T>::top() {
  return (this->stack.top());
}

template <typename T>
const T &MutantStack<T>::top() const {
  return (this->stack.top());
}

template <typename T>
bool MutantStack<T>::empty() const {
  return (this->stack.empty());
}

template <typename T>
size_t MutantStack<T>::size() const {
  return (this->stack.size());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return (c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return (c.end());
}
