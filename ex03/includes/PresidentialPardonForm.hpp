#ifndef EX02_PRESIDENTIAL_PARDON_FORM_HPP_
#define EX02_PRESIDENTIAL_PARDON_FORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string target_;
  void executeAction(Bureaucrat const &executor) const;

public:
  PresidentialPardonForm();
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  void execute(Bureaucrat const &executor) const;
};

#endif
