#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <fstream>

#define ROBOTOMY_REQUEST_SIGN_GRADE 72
#define ROBOTOMY_REQUEST_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE),
      target_("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE),
      target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE) {
  this->target_ = other.target_;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    this->target_ = other.target_;
  }
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!(AForm::isSign(this->getIsSign())))
    throw AForm::UnsignedException();
  else if (!(AForm::isExecute(this->getSignGrade(), this->getExecGrade())))
    throw AForm::GradeTooLowException();
  else
    this->executeAction(executor);
}

void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const {
  double probability = 50.0;
  int random = rand() % 100;
  if (random < probability)
    std::cout << this->target_
              << " has been robotomized successfully. signed by "
              << executor.getName() << std::endl;
  else
    std::cerr << this->target_ << " has been failed. signed by "
              << executor.getName() << std::endl;
}
