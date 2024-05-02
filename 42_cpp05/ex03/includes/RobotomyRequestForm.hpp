#ifndef EX03_ROBOTOMY_REQUEST_FORM_HPP_
#define EX03_ROBOTOMY_REQUEST_FORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  std::string target_;
  void executeAction() const;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const;
  const std::string &getTarget() const;
};

#endif