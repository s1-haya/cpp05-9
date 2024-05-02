#include "Bureaucrat.hpp"

#include <stdexcept>

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name) : name_(name), grade_(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name_(name) {
  if (HIGHEST_GRADE > grade)
    throw Bureaucrat::GradeTooLowException();
  else if (LOWEST_GRADE < grade)
    throw Bureaucrat::GradeTooHighException();
  else
    this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_ + "_copy"), grade_(other.grade_) {
  if (HIGHEST_GRADE > other.grade_)
    throw Bureaucrat::GradeTooHighException();
  else if (LOWEST_GRADE < other.grade_)
    throw Bureaucrat::GradeTooLowException();
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

const std::string &Bureaucrat::getName() const { return (this->name_); }

unsigned int Bureaucrat::getGrade() const { return (this->grade_); }

void Bureaucrat::signForm(AForm const &form) const {
  if (form.getIsSign())
    std::cout << this->name_ << " signed " << form.getName() << std::endl;
  else
    std::cout << this->name_ << " couldn’t sign " << form.getName()
              << " because " << this->name_ << "'s grade(" << this->grade_
              << ") is not higher than " << form.getName() << "'s singGrade("
              << form.getSignGrade() << ")" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const{
  try {
    form.execute(*this);
    std::cout << this->name_ << " executed " << form.getName() << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << this->name_ << " couldn't execute " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("Bureaucrat: Grade is too high."){};
Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("Bureaucrat: Grade is too low."){};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data) {
  os << data.getName() << ", bureaucrat grade " << data.getGrade();
  return (os);
}
