#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testPresidentialPardonForm(void) {
  testTitle("test presidential pardon form");
  PresidentialPardonForm presidential;
  std::cout << presidential << std::endl;
  Bureaucrat cole("J cole", 4);
  cole.executeForm(presidential);
  try {
    presidential.beSigned(cole);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  cole.executeForm(presidential);
    Bureaucrat drake("Drake", 150);
  drake.executeForm(presidential);
    try {
    presidential.beSigned(drake);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(presidential);
}
