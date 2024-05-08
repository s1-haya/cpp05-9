#ifndef TEST_ASSERT_
#define TEST_ASSERT_

#include <iostream>

template <typename T>
void testAssert(const T& expect , const T& output) {
	if (expect == output) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "KO" << std::endl;
		std::cout << "Except: " << expect << std::endl;
		std::cout << "Output: " << output << std::endl;
	}
}

template <typename T>
void testNotAssert(const T& expect , const T& output) {
	if (expect != output) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "KO" << std::endl;
		std::cout << "Except: " << expect << std::endl;
		std::cout << "Output: " << output << std::endl;
	}
}

template <typename T>
void testIsNULL(const T& output) {
	if (NULL == output) {
		std::cout << "OK" << std::endl;
	} else {
		std::cout << "KO" << std::endl;
		std::cout << "Except: " << "NULL" << std::endl;
		std::cout << "Output: " << output << std::endl;
	}
}

#endif
