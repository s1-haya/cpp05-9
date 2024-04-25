#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testPresidentialPardonForm(void) {
  testTitle("test presidential pardon form");
  PresidentialPardonForm presidential;
  std::cout << presidential << std::endl;
  Bureaucrat cole("J cole", 4);
  try {
      presidential.execute(cole);
      presidential.beSigned(cole);
      presidential.execute(cole);
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }
}
