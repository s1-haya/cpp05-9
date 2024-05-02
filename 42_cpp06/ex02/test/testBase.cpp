#include "Base.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>

class Bad : public Base {};

void testTitle(const std::string title);

void testBase(void) {
	std::srand((unsigned)time(NULL));
	testTitle("Test Base: Base * generate(void);");
	Base* base = generate();
	testTitle("Test Base: void identify(Base* p);");
	Base* bad = new Bad();
	identify(base);
	identify(bad);
	identify(NULL);
	testTitle("Test Base: void identify(Base& p);");
	if (base)
		identify(*base);
	if (bad)
		identify(*bad);
	delete base;
	delete bad;
}
