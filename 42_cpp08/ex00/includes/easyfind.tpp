#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include "easyfind.hpp"

template <typename T>
int easyfind(const T &container, int value) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw(std::runtime_error("This value wasn't found in this container."));
  return (*it);
};
