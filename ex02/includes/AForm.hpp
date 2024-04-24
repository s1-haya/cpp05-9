#ifndef EX02_AFORM_HPP_
#define EX02_AFORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm {
private:
  const std::string name_;
  bool isSign_;
  const unsigned int signGrade_;
  const unsigned int execGrade_;

public:
  AForm(void);
  AForm(const std::string name);
  AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);
  virtual ~AForm(void) = 0;
  const std::string getName(void) const;
  bool getIsSign(void) const;
  unsigned int getSignGrade(void) const;
  unsigned int getExecGrade(void) const;
  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
  void checkExecute(bool isSign, const unsigned int signGrade,
                    const unsigned int execGrade) const;
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class UnsignedException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
