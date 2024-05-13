#include <cassert>
#include <cstdlib>
#include <iostream>

#include "MutantStack.hpp"

void testTitle(const std::string title);

void testSpan(void) {
  testTitle("Mutant Stack");
    MutantStack<int> a;
    for (std::size_t i = 0; i < 5; i++) {
      a.push(i);
    }
    std::cout << "Iterataor: ";
    for (std::deque<int>::iterator it = a.begin(); it != a.end(); it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Iterataor Reverse: ";
    for (std::deque<int>::reverse_iterator it = a.rbegin(); it != a.rend();
         it++) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "empty: ";
    if (a.empty()) {
      std::cout << "true" << std::endl;
      std::cout << "size: " << a.size() << std::endl;
    } else {
      std::cout << "false" << std::endl;
      std::cout << "top: " << a.top() << std::endl;
      std::cout << "size: " << a.size() << std::endl;
      std::cout << "pop: ";
      for (std::size_t i = 0; i < 5; i++) {
        std::cout << a.top() << " ";
        a.pop();
      }
      std::cout << std::endl;
    }
    // You have to check the stack for being empty before you try to access top
    // because calling pop_back on an empty container is undefined.
    std::cout << "empty: ";
    if (a.empty()) {
      std::cout << "true" << std::endl;
      std::cout << "size: " << a.size() << std::endl;
    } else {
      std::cout << "false" << std::endl;
      std::cout << "top: " << a.top() << std::endl;
      std::cout << "size: " << a.size() << std::endl;
    }

    std::cout << std::endl;
    std::stack<int> copy_stack_a(a);
    std::cout << "Copy from MutantStack to Stack class Iterataor: error: no "
                 "member named 'begin' in 'std::stack<int>'";
    // for (std::deque<int>::iterator it = copy_stack_a.begin(); it !=
    // copy_stack_a.end(); it++) {
    //   std::cout << *it << " ";
    // }
    std::cout << std::endl;
    std::cout << "Copy from MutantStack to Stack class Reverse Itearaotr: "
                 "error: no member named 'rbegin' in 'std::stack<int>'";
    // for (std::deque<int>::reverse_iterator it = copy_stack_a.rbegin(); it !=
    // copy_stack_a.rend();
    //      it++) {
    //   std::cout << *it << " ";
    // }
    std::cout << std::endl;
    std::cout << "empty: ";
    if (copy_stack_a.empty()) {
      std::cout << "true" << std::endl;
      std::cout << "size: " << copy_stack_a.size() << std::endl;
    } else {
      std::cout << "false" << std::endl;
      std::cout << "top: " << copy_stack_a.top() << std::endl;
      std::cout << "size: " << copy_stack_a.size() << std::endl;
      std::cout << "pop: ";
      for (std::size_t i = 0; i < 5; i++) {
        std::cout << copy_stack_a.top() << " ";
        copy_stack_a.pop();
      }
      std::cout << std::endl;
    }

    // You have to check the stack for being empty before you try to access top
    // because calling pop_back on an empty container is undefined.
    std::cout << "empty: ";
    if (copy_stack_a.empty()) {
      std::cout << "true" << std::endl;
      std::cout << "size: " << copy_stack_a.size() << std::endl;
    } else {
      std::cout << "false" << std::endl;
      std::cout << "top: " << copy_stack_a.top() << std::endl;
      std::cout << "size: " << copy_stack_a.size() << std::endl;
    }

    testTitle("Subject Sample Test");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
}
