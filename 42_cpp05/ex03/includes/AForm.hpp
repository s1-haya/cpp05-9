#ifndef EX03_AFORM_HPP_
#define EX03_AFORM_HPP_

#include <string>

#include "Bureaucrat.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat;

class AForm {
 private:
  const std::string name_;
  bool isSign_;
  const unsigned int signGrade_;
  const unsigned int execGrade_;

 protected:
  AForm();
  AForm(const std::string name);
  AForm(const std::string name, unsigned int signGrade, unsigned int execGrade);
  AForm &operator=(const AForm &other);
  AForm(const AForm &other);

 public:
  virtual ~AForm() = 0;
  const std::string getName() const;
  bool getIsSign() const;
  void setIsSign(bool isSign);
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;
  void beSigned(Bureaucrat const &bureaucrat);
  virtual void execute(Bureaucrat const &executor) const = 0;
  bool isSign(bool isSign) const;
  bool isExecute(const unsigned int execGrade) const;
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
    FormIsAlreadySigned(const std::string &message);
  };
  class UnsignedException : public std::out_of_range {
   public:
    UnsignedException();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
