#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm()
    : name_("default"),
      isSign_(false),
      signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

AForm::AForm(const std::string name)
    : name_(name),
      isSign_(false),
      signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

AForm::AForm(const std::string name, unsigned int signGrade,
             unsigned int execGrade)
    : name_(name),
      isSign_(false),
      signGrade_(signGrade),
      execGrade_(execGrade) {
  if (HIGHEST_GRADE > signGrade || HIGHEST_GRADE > execGrade) {
    throw Bureaucrat::GradeTooLowException();
  } else if (LOWEST_GRADE < signGrade || LOWEST_GRADE < execGrade)
    throw Bureaucrat::GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : name_(other.name_ + "_copy"),
      isSign_(other.isSign_),
      signGrade_(other.signGrade_),
      execGrade_(other.execGrade_) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    const_cast<std::string &>(this->name_) = other.name_;
    const_cast<unsigned int &>(this->signGrade_) = other.signGrade_;
    const_cast<unsigned int &>(this->execGrade_) = other.execGrade_;
    this->isSign_ = other.isSign_;
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  std::string isSign = "false";
  if (form.getIsSign()) isSign = "true";

  os << "Form name: " << form.getName() << "\nForm isSign: " << isSign
     << "\nForm signGrade: " << form.getSignGrade()
     << "\nForm execGrade: " << form.getExecGrade();
  return (os);
}

AForm::~AForm() {}

const std::string AForm::getName() const { return (this->name_); }
bool AForm::getIsSign() const { return (this->isSign_); }
void AForm::setIsSign(bool isSign) { this->isSign_ = isSign; }
unsigned int AForm::getSignGrade() const { return (this->signGrade_); }
unsigned int AForm::getExecGrade() const { return (this->execGrade_); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= this->signGrade_) {
    if (this->isSign_)
      std::cout << this->name_ << " is already signed." << std::endl;
    else {
      std::cout << this->name_ << " is signed by " << bureaucrat.getName()
                << std::endl;
      this->isSign_ = true;
    }
  } else {
    throw(AForm::GradeTooLowException());
  }
}

bool AForm::isSign(bool isSign) const {
  if (isSign) return (true);
  return (false);
}

bool AForm::isExecute(const unsigned int execGrade) const {
  if (this->execGrade_ >= execGrade) return (true);
  return (false);
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("Exception: Form's grade is too high."){};

AForm::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("Exception: Form's grade is too low."){};

AForm::UnsignedException::UnsignedException()
    : std::out_of_range("Exception: Form is unsigned ... "){};
