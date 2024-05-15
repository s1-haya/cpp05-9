#ifndef EX02_MUTANT_STACK_HPP_
#define EX02_MUTANT_STACK_HPP_

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
 public:
  MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack();
  typedef typename std::stack<T>::container_type container;
  typedef typename container::iterator iterator;
  typedef typename container::const_iterator const_iterator;
  typedef typename container::reverse_iterator reverse_iterator;
  typedef typename container::const_reverse_iterator const_reverse_iterator;
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
