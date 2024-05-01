#include "Intern.hpp"

#include <iostream>

const std::string Intern::names_[3] = {"shrubbery creation", "robotomy request",
                                       "presidential pardon"};
AForm* (Intern::*Intern::forms_[3])(const std::string&) const = {&Intern::newShrubberyCreation,
                                  &Intern::newRobotomyRequest,
                                  &Intern::newPresidentialPardon};

    Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
  if (this != &other) {
  }
  return *this;
}

AForm* Intern::newShrubberyCreation(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::newRobotomyRequest(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::newPresidentialPardon(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form,
                        const std::string& target) const {
  for (int i = 0; i < 3; i++)
    if (names_[i] == form) return (this->*forms_[i])(target);
  throw FormNotFoundException();
}

Intern::FormNotFoundException::FormNotFoundException()
    : std::out_of_range("Error: Form isn't Found.") {}
