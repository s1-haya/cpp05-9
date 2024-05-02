#include <iostream>

template <typename T>
T Sum(T a, T b) {
    return a + b;
}

template <typename T>
void swap(T* a, T* b) {
	T* tmp;

	tmp = *a;
	*a = *b;
	*b = *a;
}

int main(void) {
	std::string a = "apple";
	std::string b = "pen";

	std::cout << "a: " << a;
	std::cout << " ";
	std::cout << "b: " << b;
	swap(a, b);
	std::cout << std::endl;
	std::cout << "a: " << a;
	std::cout << " ";
	std::cout << "b: " << b;
	// std::cout << Sum<int>(1, 1) << std::endl;
	// std::cout << Sum<float>(1.4, 1) << std::endl;
	// std::cout << Sum<double>(1, 1) << std::endl;
	return (0);
}
