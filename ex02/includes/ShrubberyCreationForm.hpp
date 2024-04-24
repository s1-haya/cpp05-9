#ifndef EX02_SHRUBBERY_CREATION_FORM_HPP_
#define EX02_SHRUBBERY_CREATION_FORM_HPP_

#include "AForm.hpp"

#define SHRUBBERY_CREATION_SIGN_GRADE 145
#define SHRUBBERY_CREATION_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm {
private:
  std::string target_;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string name);
  ~ShrubberyCreationForm();
  void execute(Bureaucrat const &executor) const;
  void action(Bureaucrat const &executor) const;
};

#endif
