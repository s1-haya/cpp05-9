#include "Base.hpp"
#include <iostream>
#include <cassert>

void testTitle(const std::string title);

void testBase(void) {
	testTitle("Test Base: Base * generate(void);");
	testTitle("Test Base: void identify(Base* p);");
	testTitle("Test Base: void identify(Base& p);");

}
