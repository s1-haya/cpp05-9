#ifndef EX01_BUREAUCRAT_HPP_
#define EX01_BUREAUCRAT_HPP_

#include <iostream>
// #include <stdexcept>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat {
private:
  const std::string name_;
  unsigned int grade_;
  Bureaucrat &operator=(const Bureaucrat &other);

public:
  Bureaucrat();
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  const std::string getName() const;
  unsigned int getGrade() const;
  void signForm(Form form);
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
