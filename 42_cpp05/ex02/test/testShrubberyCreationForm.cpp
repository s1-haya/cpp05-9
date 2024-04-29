#include "ShrubberyCreationForm.hpp"

void testTitle(const std::string title);

void testShrubberyCreationForm(void) {
  testTitle("test shrubbery init");
  ShrubberyCreationForm shrubbery;
  std::cout << shrubbery << std::endl;
  ShrubberyCreationForm home("home");
  std::cout << home << std::endl;

  testTitle("test shrubbery exec");
	ShrubberyCreationForm Shrubbery;
	Bureaucrat cole("J cole", 4);
  cole.executeForm(Shrubbery);
  try {
    Shrubbery.beSigned(cole);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  cole.executeForm(Shrubbery);
    Bureaucrat drake("Drake", 150);
  drake.executeForm(Shrubbery);
    try {
    Shrubbery.beSigned(drake);
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  drake.executeForm(Shrubbery);
}
