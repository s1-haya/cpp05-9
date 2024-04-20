#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testBureaucrat(void)
{
	testTitle("TEST BUREAUCRAT BEHAVIOR");
	Bureaucrat data;
	data.setGrade(149);
	data.incrementGrade();
	data.incrementGrade();
	data.incrementGrade();
	std::cout << data << std::endl;
}
