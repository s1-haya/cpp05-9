#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : name_(name), grade_(grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade_ = other.grade_;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  try {
    if (HIGHEST_GRADE >= this->grade_) {
      throw Bureaucrat::GradeTooHighException();
    } else
      this->grade_--;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::decrementGrade() {
  try {
    if (LOWEST_GRADE <= this->grade_) {
      throw Bureaucrat::GradeTooLowException();
    } else
      this->grade_++;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

const std::string Bureaucrat::getName() const { return (this->name_); }

unsigned int Bureaucrat::getGrade() const { return (this->grade_); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data) {
  os << data.getName() << ", bureaucrat grade " << data.getGrade();
  return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Exception: Bureaucrat's grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Exception: Bureaucrat's grade is too low");
}
