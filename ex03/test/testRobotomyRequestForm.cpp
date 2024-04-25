#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

void testTitle(const std::string title);

void testRobotomyRequestForm(void) {
  std::srand((unsigned)time(NULL));
  testTitle("test robotomy request form");
  RobotomyRequestForm robotomy;
  std::cout << robotomy << std::endl;
  Bureaucrat cole("J cole", 4);
  try {
    // robotomy.execute(cole);
    robotomy.beSigned(cole);
    robotomy.execute(cole);
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
}
