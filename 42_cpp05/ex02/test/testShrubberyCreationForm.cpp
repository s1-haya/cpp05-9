#include "ShrubberyCreationForm.hpp"

void testTitle(const std::string title);

void testShrubberyCreationForm(void) {
  testTitle("test shrubbery exec");
  ShrubberyCreationForm Shrubbery;
  std::cerr << Shrubbery << std::endl;

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 137);
    cole.executeForm(Shrubbery);
    Shrubbery.beSigned(cole);
    cole.executeForm(Shrubbery);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;

  Bureaucrat drake("Drake");
  drake.executeForm(Shrubbery);
  try {
    Shrubbery.beSigned(drake);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(Shrubbery);

  testTitle("Shrubbery Creation Form: Copy");
  ShrubberyCreationForm form;
  std::cout << "default target: "<< form.getTarget() << std::endl;
  ShrubberyCreationForm highTarget("high");
  form = highTarget;
  std::cout << "assignment copy target: "<< form.getTarget() << std::endl;
  ShrubberyCreationForm copyForm = form;
  std::cout << "copy constructor target: "<< copyForm.getTarget() << std::endl;
}
