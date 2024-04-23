#ifndef EX01_BUREAUCRAT_HPP_
#define EX01_BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

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
  const std::string getName() const;
  unsigned int getGrade() const;
  void signForm(const Form &form);
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data);

#endif
