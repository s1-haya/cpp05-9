#include <limits>
#include <iostream>

int main(void) {
  std::cout << "char: not cast int" << std::endl;
  std::cout << "min" << std::numeric_limits<char>::min()<< std::endl;
  std::cout << "max" << std::numeric_limits<char>::max() << std::endl;
  std::cout << std::endl;
  std::cout << "char: cast int" << std::endl;
  std::cout << "min" << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
  std::cout << "max" << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
  std::cout << std::endl;
  std::cout << "char: define char min and max" << std::endl;
  std::cout << "min" << CHAR_MIN << std::endl;
  std::cout << "max" << CHAR_MAX << std::endl;
  std::cout << std::endl;
  std::cout << "int:" << std::endl;
  std::cout << "min" << std::numeric_limits<int>::min()<< std::endl;
  std::cout << "max" << std::numeric_limits<int>::max() << std::endl;
  std::cout << std::endl;
  std::cout << "int: define int min and max" << std::endl;
  std::cout << "min" << INT_MIN << std::endl;
  std::cout << "max" << INT_MAX << std::endl;
  std::cout << std::endl;
  return (0);
}

  // std::cout << "min" << std::numeric_limits<float>::min()<< std::endl;
  // std::cout << "max" << std::numeric_limits<float>::max() << std::endl;
  // std::cout << "min" << FL_MIN << std::endl;
  // std::cout << "max" << FL_MAX << std::endl;