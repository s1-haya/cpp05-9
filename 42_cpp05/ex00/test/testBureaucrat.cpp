#include "Bureaucrat.hpp"

void testTitle(const std::string title);

void testBureaucrat(void) {
  testTitle("TEST BUREAUCRAT INCREMENT");
  try {
    Bureaucrat beginer;
    std::cout << beginer << std::endl;
    beginer.decrementGrade();
    std::cout << beginer << std::endl;
    beginer.decrementGrade();
    std::cout << beginer << std::endl;
    beginer.decrementGrade();
    std::cout << beginer << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  testTitle("TEST BUREAUCRAT DECREMENT");
  try {
    Bureaucrat pro("J COLE", 2);
    std::cout << pro << std::endl;
    pro.incrementGrade();
    std::cout << pro << std::endl;
    pro.incrementGrade();
    std::cout << pro << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("TEST BUREAUCRAT COPY");
  try {
    Bureaucrat top("top player", 1);
    Bureaucrat jcole("j", 3);
    top = jcole;
    std::cout << top << std::endl;
    Bureaucrat proCopy = top;
    std::cout << proCopy << std::endl;
    proCopy.incrementGrade();
    proCopy.incrementGrade();
    proCopy.incrementGrade();
    std::cout << proCopy << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  testTitle("TEST BUREAUCRAT ERROR");
  try {
    Bureaucrat intMax("int max", -1);
    std::cout << intMax << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    Bureaucrat zero("zero", 0);
    std::cout << zero << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
