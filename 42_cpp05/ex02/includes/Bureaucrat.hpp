#ifndef EX02_BUREAUCRAT_HPP_
#define EX02_BUREAUCRAT_HPP_

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm;

class Bureaucrat {
private:
  const std::string name_;
  unsigned int grade_;

public:
  Bureaucrat();
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  const std::string &getName() const;
  unsigned int getGrade() const;
  void signForm(const AForm &form);
  void executeForm(AForm const &form);
  class GradeTooHighException : public std::out_of_range {
  public:
    GradeTooHighException();
  };
  class GradeTooLowException : public std::out_of_range {
  public:
    GradeTooLowException();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data);

#endif
