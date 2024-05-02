#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <fstream>

#include "AForm.hpp"

#define ROBOTOMY_REQUEST_SIGN_GRADE 72
#define ROBOTOMY_REQUEST_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE),
      target_("target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE),
      target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE),
      target_(other.target_ + "_copy") {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  if (this != &other) {
    this->setIsSign(other.getIsSign());
    this->target_ = other.target_;
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!(AForm::isSign(this->getIsSign())))
    throw AForm::UnsignedException();
  else if (!(AForm::isExecute(executor.getGrade())))
    throw AForm::GradeTooLowException();
  else
    this->executeAction();
}

void RobotomyRequestForm::executeAction() const {
  double probability = 50.0;
  int random = rand() % 100;
  if (random < probability)
    std::cout << this->target_ << " has been robotomized successfully."
              << std::endl;
  else
    std::cerr << this->target_ << " has been failed." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const {
  return (this->target_);
}
