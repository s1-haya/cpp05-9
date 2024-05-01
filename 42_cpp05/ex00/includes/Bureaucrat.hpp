#ifndef EX00_BUREAUCRAT_HPP_
#define EX00_BUREAUCRAT_HPP_

#include <iostream>
#include <stdexcept>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
 private:
  const std::string name_;
  unsigned int grade_;
  Bureaucrat& operator=(const Bureaucrat& other);

 public:
  Bureaucrat();
  Bureaucrat(const std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();
  void incrementGrade();
  void decrementGrade();
  const std::string getName() const;
  unsigned int getGrade() const;
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& data);

#endif
