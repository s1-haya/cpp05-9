#include "Base.hpp"

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
  Base* p = NULL;
  int random = std::rand() % 3;
  switch (random) {
    case 0:
      std::cout << "A class created." << std::endl;
      p = new A();
      break;
    case 1:
      std::cout << "B class created." << std::endl;
      p = new B();
      break;
    case 2:
      std::cout << "C class created." << std::endl;
      p = new C();
      break;
    default:
      break;
  }
  return (p);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cerr << "Base pointer isn't Class A, B, C.";
	std::cout << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (std::bad_cast& e) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "B" << std::endl;
    } catch (std::bad_cast& e) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
      } catch (std::bad_cast& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
      }
    }
  }
}
