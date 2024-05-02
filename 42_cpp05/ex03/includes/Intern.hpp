#ifndef EX03_INTERN_HPP_
#define EX03_INTERN_HPP_

#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 private:
  static const std::string names_[3];
  static AForm *(Intern::*forms_[3])(const std::string &) const;
  AForm *newShrubberyCreation(const std::string &target) const;
  AForm *newRobotomyRequest(const std::string &target) const;
  AForm *newPresidentialPardon(const std::string &target) const;

 public:
  Intern();
  Intern &operator=(const Intern &other);
  Intern(const Intern &other);
  ~Intern();
  AForm *makeForm(const std::string &name, const std::string &target) const;
};

#endif
