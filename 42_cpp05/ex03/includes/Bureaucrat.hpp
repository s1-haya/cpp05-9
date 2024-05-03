#ifndef EX03_BUREAUCRAT_HPP_
#define EX03_BUREAUCRAT_HPP_

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
  Bureaucrat(const std::string name);
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  const std::string &getName() const;
  unsigned int getGrade() const;
  void signForm(AForm &form);
  void executeForm(AForm const &form) const;
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
