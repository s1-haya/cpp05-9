#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#define PRESIDENTIAL_PARDON_SIGN_GRADE 25
#define PRESIDENTIAL_PARDON_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE),
      target_("target") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm("PresidentialPardonForm", PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE) {
  this->target_ = other.target_;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    this->target_ = other.target_;
  }
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!(AForm::isSign(this->getIsSign())))
    throw AForm::UnsignedException();
  else if (!(AForm::isExecute(executor.getGrade())))
    throw AForm::GradeTooLowException();
  else
    this->executeAction();
}

void PresidentialPardonForm::executeAction() const {
  std::cout << this->target_
            << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
