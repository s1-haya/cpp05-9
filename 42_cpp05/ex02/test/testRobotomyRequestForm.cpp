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

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    cole.executeForm(robotomy);
    robotomy.beSigned(cole);
    cole.executeForm(robotomy);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;

  Bureaucrat drake("Drake");
  drake.executeForm(robotomy);
  try {
    robotomy.beSigned(drake);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(robotomy);
}
