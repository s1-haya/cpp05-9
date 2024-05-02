#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testPresidentialPardonForm(void) {
  testTitle("test presidential pardon form");
  PresidentialPardonForm presidential;
  std::cout << presidential << std::endl;

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    cole.executeForm(presidential);
    presidential.beSigned(cole);
    cole.executeForm(presidential);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;

  Bureaucrat drake("Drake");
  drake.executeForm(presidential);
  try {
    presidential.beSigned(drake);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(presidential);

  testTitle("Presidential Pardon Form: Copy");
    PresidentialPardonForm form;
    std::cout << "default target: "<< form.getTarget() << std::endl;
    PresidentialPardonForm highTarget("high");
    form = highTarget;
    std::cout << "assignment copy target: "<< form.getTarget() << std::endl;
    PresidentialPardonForm copyForm = form;
    std::cout << "copy constructor target: "<< copyForm.getTarget() << std::endl;
}
