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
  cole.executeForm(robotomy);
    try {
    robotomy.beSigned(cole);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  cole.executeForm(robotomy);
  Bureaucrat drake("Drake", 150);
  drake.executeForm(robotomy);
    try {
    robotomy.beSigned(drake);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(robotomy);
}
