#ifndef EX02_ROBOTOMY_REQUEST_FORM_HPP_
#define EX02_ROBOTOMY_REQUEST_FORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
  std::string target_;
  void executeAction() const;
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const;
};

#endif