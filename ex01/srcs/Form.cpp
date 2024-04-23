#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name_("default"), isSign_(false), signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

Form::Form(const std::string name, unsigned int signGrade,
           unsigned int execGrade)
    : name_(name), isSign_(false), signGrade_(signGrade),
      execGrade_(execGrade) {
  try {
    if (LOWEST_GRADE < signGrade || LOWEST_GRADE < execGrade)
      throw(Form::GradeTooLowException());
    else if (HIGHEST_GRADE > signGrade || HIGHEST_GRADE > signGrade)
      throw(Form::GradeTooHighException());
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  std::string isSign = "false";
  if (form.getIsSign())
    isSign = "true";

  os << "Form name: " << form.getName() << "\nForm isSign: " << isSign
     << "\nForm signGrade: " << form.getSignGrade()
     << "\nForm execGrade: " << form.getExecGrade();
  return (os);
}

Form::~Form() {}

const std::string Form::getName() const { return (this->name_); }
bool Form::getIsSign() const { return (this->isSign_); }
unsigned int Form::getSignGrade() const { return (this->signGrade_); }
unsigned int Form::getExecGrade() const { return (this->execGrade_); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  try {
    if (bureaucrat.getGrade() <= this->signGrade_) {
      if (this->isSign_)
        std::cout << this->name_ << " is already signed." << std::endl;
      else {
        std::cout << this->name_ << " is signed by " << bureaucrat.getName()
                  << std::endl;
        this->isSign_ = true;
      }
    } else {
      throw(Form::GradeTooLowException());
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

const char *Form::GradeTooHighException::what() const throw() {
  return ("Form: Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("Form: Grade is too low");
}
