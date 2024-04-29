#include "Intern.hpp"

void testTitle(const std::string title);

void testIntern(void) {
  testTitle("test Intern");
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
