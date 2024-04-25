#include "ShrubberyCreationForm.hpp"

void testTitle(const std::string title);

void testShrubberyCreationForm(void) {
  testTitle("test shrubbery init");
  ShrubberyCreationForm shrubbery;
  std::cout << shrubbery << std::endl;
  ShrubberyCreationForm home("home");
  std::cout << home << std::endl;

  testTitle("test shrubbery exec");
	ShrubberyCreationForm form;
	Bureaucrat cole("J cole", 4);
  try {
    // form.execute(cole);
    form.beSigned(cole);
    form.execute(cole);
  }
  catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
}
