#include <vector>
#include <exception>
#include <iostream>

int main(void)
{
	std::vector<int> v;
	try {
		auto a = v.begin();
		auto b = v.end();
		// Calling this function on an empty container causes undefined behavior.
		// auto c = v.back();
		std::cout << "a: " << a.base() << std::endl;
		std::cout << "b: " << b.base() << std::endl;
		// std::cout << "c: " << c << std::endl;
	}catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return(0);
}
