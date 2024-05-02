#ifndef EX03_PRESIDENTIAL_PARDON_FORM_HPP_
#define EX03_PRESIDENTIAL_PARDON_FORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  std::string target_;
  void executeAction() const;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  const std::string &getTarget() const;
  void execute(Bureaucrat const &executor) const;
};

#endif
