#include "ShrubberyCreationForm.hpp"

void testTitle(const std::string title);

void testShrubberyCreationForm(void) {
  testTitle("test shrubbery");
  ShrubberyCreationForm shrubbery;
  std::cout << shrubbery << std::endl;
}
