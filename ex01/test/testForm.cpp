#include "Form.hpp"

void testTitle(const std::string title);

void testForm(void) {
	testTitle("test form");
	// Form form;
	// std::cout << form << std::endl;
	testTitle("test too low");
	Form tooLow("form", -1, -1);
	std::cout << tooLow << std::endl;

	testTitle("test too high");
	Form tooHigh("form", 0, 0);
	std::cout << tooHigh << std::endl;

	testTitle("test be signed");
	Form form;
	std::cout << form << std::endl;
	Bureaucrat cole("J Cole", 2);
	form.beSigned(cole);
	std::cout << cole << std::endl;
	std::cout << form << std::endl;
	cole.signForm(form);

	testTitle("test not be signed");
	Bureaucrat jay("Jay-z", 150);
	Form low("form", 149, 149);
	low.beSigned(jay);
	std::cout << jay << std::endl;
	std::cout << low << std::endl;
	jay.signForm(low);
}
