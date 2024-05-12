#include <vector>
#include "easyfind.hpp"

void testTitle(const std::string title);

void testVectorInt() {
  testTitle("Test Vector");
	std::vector<int> v;
	for(size_t i = 0; i < 5; i++)
		v.push_back(i);

	std::cout << "v = ";
	for(std::vector<int>::iterator i = v.begin(), e = v.end(); i != e; i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << easyfind(v, 1) << std::endl;
		std::cout << easyfind(v, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

  testTitle("Test Const Vector");
	const std::vector<int> cv = v;
	try {
		std::cout << easyfind(v, 1) << std::endl;
		std::cout << easyfind(v, 42) << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
