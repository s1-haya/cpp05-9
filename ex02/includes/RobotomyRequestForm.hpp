#ifndef EX02_ROBOTOMY_REQUEST_FORM_HPP_
#define EX02_ROBOTOMY_REQUEST_FORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const;
};

#endif