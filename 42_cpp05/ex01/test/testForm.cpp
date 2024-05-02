#include "Form.hpp"

void testTitle(const std::string title);

void testForm(void) {
  testTitle("Form: be signed");
  try {
    Form form;
    std::cout << form << std::endl;
    Bureaucrat cole("J Cole", 2);
    form.beSigned(cole);
    std::cout << cole << std::endl;
    std::cout << form << std::endl;
    cole.signForm(form);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("Form: not be signed");
  try {
    Bureaucrat jay("Jay-z", 150);
    Form low("form", 149, 149);
    jay.signForm(low);
    low.beSigned(jay);
    std::cout << jay << std::endl;
    std::cout << low << std::endl;
    jay.signForm(low);
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("Form: default");
  try {
    Form form;
    std::cout << form << std::endl;
    std::cout << std::endl;
    Form copyForm = form;
    std::cout << copyForm << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("Form: copy");
  try {
    Form form;
    std::cout << form << std::endl;
    std::cout << std::endl;
    Form highForm("high", 1, 1);
    form = highForm;
    std::cout << form << std::endl;
    std::cout << std::endl;
    Form copyForm = form;
    std::cout << copyForm << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("Form: Unsigned MAX");
  try {
    Form max("form", -1, -1);
    std::cout << max << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("Form: zero");
  try {
	Form zero("form", 0, 0);
	std::cout << zero << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}
