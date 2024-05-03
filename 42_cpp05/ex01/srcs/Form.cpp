#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : name_("default"),
      isSign_(false),
      signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

Form::Form(const std::string name, unsigned int signGrade,
           unsigned int execGrade)
    : name_(name),
      isSign_(false),
      signGrade_(signGrade),
      execGrade_(execGrade) {
  if (HIGHEST_GRADE > signGrade || HIGHEST_GRADE > execGrade)
    throw(Form::GradeTooHighException());
  else if (LOWEST_GRADE < signGrade || LOWEST_GRADE < execGrade)
    throw(Form::GradeTooLowException());
}

Form::Form(const Form &other)
    : name_(other.name_ + "_copy"),
      isSign_(other.isSign_),
      signGrade_(other.signGrade_),
      execGrade_(other.execGrade_) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    const_cast<std::string &>(this->name_) = other.name_;
    const_cast<unsigned int &>(this->signGrade_) = other.signGrade_;
    const_cast<unsigned int &>(this->execGrade_) = other.execGrade_;
    this->isSign_ = other.isSign_;
  }
  return (*this);
}

Form::~Form() {}

const std::string Form::getName() const { return (this->name_); }
bool Form::getIsSign() const { return (this->isSign_); }
unsigned int Form::getSignGrade() const { return (this->signGrade_); }
unsigned int Form::getExecGrade() const { return (this->execGrade_); }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= this->signGrade_) {
    if (this->isSign_)
      throw(Form::FormIsAlreadySigned(this->name_ + " is already signed." ));
    else
      this->isSign_ = true;
  } else
    throw(Form::GradeTooLowException());
}

Form::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("Form's grade is too high."){};

Form::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("Form's grade is too low."){};

Form::FormIsAlreadySigned::FormIsAlreadySigned(const std::string& message)
    : std::out_of_range(message){};

std::ostream &operator<<(std::ostream &os, const Form &form) {
  std::string isSign = "false";
  if (form.getIsSign()) isSign = "true";

  os << "Form name: " << form.getName() << "\nForm isSign: " << isSign
     << "\nForm signGrade: " << form.getSignGrade()
     << "\nForm execGrade: " << form.getExecGrade();
  return (os);
}
