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

public:
  Form();
  Form(const std::string name, unsigned int signGrade, unsigned int execGrade);
  Form(const Form& other);
  Form &operator=(const Form &other);
  ~Form();
  const std::string getName() const;
  bool getIsSign() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;
  void beSigned(const Bureaucrat &bureaucrat);
  class GradeTooHighException : public std::out_of_range {
  public:
    GradeTooHighException();
  };
  class GradeTooLowException : public std::out_of_range {
  public:
    GradeTooLowException();
  };
  class FormIsAlreadySigned : public std::out_of_range {
    public:
      FormIsAlreadySigned(const std::string& message);
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
