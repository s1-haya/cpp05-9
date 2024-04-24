#ifndef EX02_PRESIDENTIAL_PARDON_FORM_HPP_
#define EX02_PRESIDENTIAL_PARDON_FORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const;
};

#endif
