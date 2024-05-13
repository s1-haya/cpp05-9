#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> a;
  a.push_back(INT_MAX);
  a.push_back(INT_MIN);
  long min = *(std::min_element(a.begin(), a.end()));
  long max = *(std::max_element(a.begin(), a.end()));
  unsigned long range = max - min;
  std::cout << "min: " << min << std::endl;
  std::cout << "max: " << max << std::endl;
  std::cout << "range: " << range << std::endl;
  std::cout << "UN_MAX: " << UINT_MAX << std::endl;
}
