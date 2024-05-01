#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name_(name) {
  if (HIGHEST_GRADE > grade)
    throw Bureaucrat::GradeTooHighException();
  else if (LOWEST_GRADE < grade)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_ + "_copy") {
  if (HIGHEST_GRADE > other.grade_)
    throw Bureaucrat::GradeTooHighException();
  else if (LOWEST_GRADE < other.grade_)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade_ = other.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (HIGHEST_GRADE > other.grade_)
    throw Bureaucrat::GradeTooHighException();
  else if (LOWEST_GRADE < other.grade_)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade_ = other.grade_;
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  if (HIGHEST_GRADE >= this->grade_)
    throw Bureaucrat::GradeTooHighException();
  else
    this->grade_--;
}

void Bureaucrat::decrementGrade() {
  if (LOWEST_GRADE <= this->grade_)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade_++;
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
