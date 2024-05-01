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
      isSign_(false),
      signGrade_(other.signGrade_),
      execGrade_(other.execGrade_) {
  if (HIGHEST_GRADE > other.signGrade_ || HIGHEST_GRADE > other.execGrade_)
    throw(Form::GradeTooHighException());
  else if (LOWEST_GRADE < other.signGrade_ || LOWEST_GRADE < other.execGrade_)
    throw(Form::GradeTooLowException());
}

Form &Form::operator=(const Form &other) {
  if (HIGHEST_GRADE > other.signGrade_ || HIGHEST_GRADE > other.execGrade_)
    throw(Form::GradeTooHighException());
  else if (LOWEST_GRADE < other.signGrade_ || LOWEST_GRADE < other.execGrade_)
    throw(Form::GradeTooLowException());
  else
    this->isSign_ = other.isSign_;
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
      std::cout << this->name_ << " is already signed."
                << std::endl;
    else {
      std::cout << this->name_ << " is signed by " << bureaucrat.getName()
                << std::endl;
      this->isSign_ = true;
    }
  } else
    throw(Form::GradeTooLowException());
}

Form::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("Exception: Form's grade is too high."){};

Form::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("Exception: Form's grade is too low."){};

std::ostream &operator<<(std::ostream &os, const Form &form) {
  std::string isSign = "false";
  if (form.getIsSign()) isSign = "true";

  os << "Form name: " << form.getName() << "\nForm isSign: " << isSign
     << "\nForm signGrade: " << form.getSignGrade()
     << "\nForm execGrade: " << form.getExecGrade();
  return (os);
}
