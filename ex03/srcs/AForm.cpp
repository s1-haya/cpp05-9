#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

AForm::AForm()
    : name_("default"), isSign_(false), signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

AForm::AForm(const std::string name)
    : name_(name), isSign_(false), signGrade_(LOWEST_GRADE),
      execGrade_(LOWEST_GRADE) {}

AForm::AForm(const std::string name, unsigned int signGrade,
             unsigned int execGrade)
    : name_(name), isSign_(false), signGrade_(signGrade),
      execGrade_(execGrade) {
  if (HIGHEST_GRADE > signGrade || HIGHEST_GRADE > execGrade) {
    throw Bureaucrat::GradeTooLowException();
  } else if (LOWEST_GRADE < signGrade || LOWEST_GRADE < execGrade)
    throw Bureaucrat::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  std::string isSign = "false";
  if (form.getIsSign())
    isSign = "true";

  os << "Form name: " << form.getName() << "\nForm isSign: " << isSign
     << "\nForm signGrade: " << form.getSignGrade()
     << "\nForm execGrade: " << form.getExecGrade();
  return (os);
}

AForm::~AForm() {}

const std::string AForm::getName() const { return (this->name_); }
bool AForm::getIsSign() const { return (this->isSign_); }
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
  if (isSign)
    return (true);
  return (false);
}

bool AForm::isExecute(const unsigned int signGrade,
                      const unsigned int execGrade) const {
  if (this->signGrade_ <= signGrade && this->execGrade_ <= execGrade)
    return (true);
  return (false);
}

AForm::GradeTooHighException::GradeTooHighException()
    : std::out_of_range("Exception: Form's grade is too high"){};

AForm::GradeTooLowException::GradeTooLowException()
    : std::out_of_range("Exception: Form's grade is too low"){};

AForm::UnsignedException::UnsignedException()
    : std::out_of_range("Exception: Form is unsigned ... "){};
