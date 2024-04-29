#ifndef EX03_INTERN_HPP_
#define EX03_INTERN_HPP_

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
private:
  static const std::string names_[3];
  static const AForm* forms_[3];
  AForm *newShrubberyCreation(const std::string &target) const;
  AForm *newRobotomyRequest(const std::string &target) const;
  AForm *newPresidentialPardon(const std::string &target) const;

public:
  Intern() {}
  ~Intern() {}
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  AForm *makeForm(const std::string &form, const std::string &target) const;
};

#endif
