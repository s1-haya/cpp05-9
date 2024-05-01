#ifndef EX02_PRESIDENTIAL_PARDON_FORM_HPP_
#define EX02_PRESIDENTIAL_PARDON_FORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
  std::string target_;
  void executeAction() const;
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const;
};

#endif
