#include "RobotomyRequestForm.hpp"

void testTitle(const std::string title);

void testRobotomyRequestForm(void) {
  testTitle("test robotomy request form");
  RobotomyRequestForm robotomy;
  std::cout << robotomy << std::endl;
}
