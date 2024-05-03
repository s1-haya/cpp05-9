#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

#define PRESIDENTIAL_PARDON "PresidentialPardonForm"
#define PRESIDENTIAL_PARDON_SIGN_GRADE 25
#define PRESIDENTIAL_PARDON_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(PRESIDENTIAL_PARDON, PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE),
      target_("target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(PRESIDENTIAL_PARDON, PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE),
      target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(PRESIDENTIAL_PARDON, PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE),
      target_(other.target_ + "_copy") {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &other) {
  if (this != &other) {
    this->setIsSign(other.getIsSign());
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
  std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

const std::string& PresidentialPardonForm::getTarget() const {
  return (this->target_);
}
