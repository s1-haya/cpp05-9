#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

void testTitle(const std::string title);

void testRobotomyRequestForm(void) {
  testTitle("test robotomy request form");
  std::srand((unsigned)time(NULL));
  RobotomyRequestForm robotomy;
  std::cout << robotomy << std::endl;

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 45);
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

  testTitle("Robotomy Request Form: Copy");
  RobotomyRequestForm form;
  std::cout << "default target: "<< form.getTarget() << std::endl;
  RobotomyRequestForm highTarget("high");
  form = highTarget;
  std::cout << "assignment copy target: "<< form.getTarget() << std::endl;
  RobotomyRequestForm copyForm = form;
  std::cout << "copy constructor target: "<< copyForm.getTarget() << std::endl;

  testTitle("Robotomy Request Form: couldn't be signed because the form is already signed");
  try {
    RobotomyRequestForm form;
    Bureaucrat cole("J Cole", 2);
    std::cout << form << std::endl;
    form.beSigned(cole);
    std::cout << form << std::endl;
    cole.signForm(form);
    form.beSigned(cole);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}
