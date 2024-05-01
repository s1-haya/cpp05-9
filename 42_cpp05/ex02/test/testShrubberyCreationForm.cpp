#include "ShrubberyCreationForm.hpp"

void testTitle(const std::string title);

void testShrubberyCreationForm(void) {
  testTitle("test shrubbery exec");
  ShrubberyCreationForm Shrubbery;
  std::cerr << Shrubbery << std::endl;

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
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
}
