#ifndef EX01_FORM_HPP_
#define EX01_FORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form {
private:
  const std::string name_;
  bool isSign_;
  const unsigned int signGrade_;
  const unsigned int execGrade_;
  Form &operator=(const Form &other);

public:
  Form(void);
  Form(const std::string name, unsigned int signGrade, unsigned int execGrade);
  Form(const Form& other);
  ~Form(void);
  const std::string getName(void) const;
  bool getIsSign(void) const;
  unsigned int getSignGrade(void) const;
  unsigned int getExecGrade(void) const;
  void beSigned(const Bureaucrat &bureaucrat);
  class GradeTooHighException : public std::out_of_range {
  public:
    GradeTooHighException();
  };
  class GradeTooLowException : public std::out_of_range {
  public:
    GradeTooLowException();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif