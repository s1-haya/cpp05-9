#include <list>
#include "easyfind.hpp"

void testTitle(const std::string title);

void testListInt() {
	testTitle("Test List");
	std::list<int> v;
	for(size_t i = 0; i < 5; i++)
		v.push_back(i);
	try {
		std::cout << easyfind(v, 1) << std::endl;
		std::cout << easyfind(v, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	testTitle("Test Const List");
	const std::list<int> cv = v;
	try {
		// cv.push_back(42);
		std::cout << easyfind(cv, 1) << std::endl;
		std::cout << easyfind(cv, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

