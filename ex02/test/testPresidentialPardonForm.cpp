#include "PresidentialPardonForm.hpp"

void testTitle(const std::string title);

void testPresidentialPardonForm(void) {
  testTitle("test presidential pardon form");
  PresidentialPardonForm presidential;
  std::cout << presidential << std::endl;
}
