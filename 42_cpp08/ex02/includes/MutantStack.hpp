#ifndef EX02_MUTANT_STACK_HPP_
#define EX02_MUTANT_STACK_HPP_

#include <deque>
#include <stack>

template <typename T>
class MutantStack {
 private:
  std::stack<T, std::deque<T> > stack;
  std::deque<T> c;

 public:
  typedef
      typename std::deque<T>::iterator iterator;
  MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack();
  void push(const T &value);
  void pop();
  T &top();
  const T &top() const;
  bool empty() const;
  size_t size() const;
  iterator begin();
  iterator end();
};

#include "MutantStack.tpp"

#endif
