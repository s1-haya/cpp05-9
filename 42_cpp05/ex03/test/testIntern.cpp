#include "Intern.hpp"

void testTitle(const std::string title);

void testIntern(void) {
  testTitle("test Intern");
  Intern intern;

  testTitle("Intern: shrubbery creation form");
  AForm* shrubbery = intern.makeForm("ShrubberyCreationForm", "shrubbery");

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    if (shrubbery != NULL) {
      cole.executeForm(*shrubbery);
      shrubbery->beSigned(cole);
      cole.executeForm(*shrubbery);
    }
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  delete shrubbery;

  testTitle("Intern: robotomy request form");
  AForm* robotomy = intern.makeForm("RobotomyRequestForm", "robot");

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    if (robotomy != NULL) {
      cole.executeForm(*robotomy);
      robotomy->beSigned(cole);
      cole.executeForm(*robotomy);
    }
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  delete robotomy;

  testTitle("Intern: presidential pardon form");
  AForm* president = intern.makeForm("PresidentialPardonForm", "president");

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    if (president != NULL) {
      cole.executeForm(*president);
      president->beSigned(cole);
      cole.executeForm(*president);
    }
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  delete president;

  testTitle("Intern: error form");
  AForm* tokyo = intern.makeForm("42tokyoForm", "nop");

  std::cout << std::endl;

  try {
    Bureaucrat cole("J cole", 4);
    if (tokyo != NULL) {
      cole.executeForm(*tokyo);
      tokyo->beSigned(cole);
      cole.executeForm(*tokyo);
    }
  }
  catch (const std::out_of_range& e){
    std::cerr << e.what() << std::endl;
  }
  delete tokyo;
}
