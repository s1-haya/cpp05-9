#include "Intern.hpp"

#include <iostream>

const std::string Intern::names_[3] = {
    "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
AForm* (Intern::*Intern::forms_[3])(const std::string&) const = {
    &Intern::newShrubberyCreation, &Intern::newRobotomyRequest,
    &Intern::newPresidentialPardon};

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::newShrubberyCreation(const std::string& target) const {
  return (new ShrubberyCreationForm(target));
}

AForm* Intern::newRobotomyRequest(const std::string& target) const {
  return (new RobotomyRequestForm(target));
}

AForm* Intern::newPresidentialPardon(const std::string& target) const {
  return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name,
                        const std::string& target) const {
  AForm* form = NULL;
  for (int i = 0; i < 3; i++)
    if (names_[i] == name) {
      form = (this->*forms_[i])(target);
      if (form == NULL) {
        std::cerr << "Error: Memory allocation failed." << std::endl;
        return (NULL);
      }
      std::cout << "Intern creates " << *form << std::endl;
      return (form);
    }
  std::cerr << "Error: " << name << " isn't found." << std::endl;
  return (form);
}
