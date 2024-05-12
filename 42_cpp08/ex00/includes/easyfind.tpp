#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

template <typename T>
int easyfind(const T &container, int value) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("This value wasn't found in this container."));
	return (*it);
};
