#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testBureaucrat(void) {
  testTitle("TEST BUREAUCRAT BEHAVIOR");
  testTitle("TEST BUREAUCRAT INCREMENT");
  Bureaucrat beginer;
  std::cout << beginer << std::endl;
  beginer.decrementGrade();
  std::cout << beginer << std::endl;
  beginer.decrementGrade();
  beginer.decrementGrade();
  std::cout << beginer << std::endl;
  beginer.decrementGrade();
  std::cout << beginer << std::endl;

  testTitle("TEST BUREAUCRAT DECREMENT");
  Bureaucrat pro("J COLE", 2);
  std::cout << pro << std::endl;
  pro.incrementGrade();
  std::cout << pro << std::endl;
  pro.incrementGrade();
  std::cout << pro << std::endl;

  testTitle("TEST BUREAUCRAT COPY");
  Bureaucrat proCopy(pro);
  std::cout << proCopy << std::endl;
  proCopy.incrementGrade();
  std::cout << proCopy << std::endl;

  testTitle("TEST BUREAUCRAT ERROR");
  Bureaucrat intMax("int max", -1);
  try {
    if (HIGHEST_GRADE > intMax.getGrade())
      throw Bureaucrat::GradeTooHighException();
    else if (LOWEST_GRADE < intMax.getGrade())
      throw Bureaucrat::GradeTooLowException();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << intMax << std::endl;
  Bureaucrat zero("zero", 0);
  try {
    if (HIGHEST_GRADE > zero.getGrade())
      throw Bureaucrat::GradeTooHighException();
    else if (LOWEST_GRADE < zero.getGrade())
      throw Bureaucrat::GradeTooLowException();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << zero << std::endl;
}
