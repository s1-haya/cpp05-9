#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

#define SHRUBBERY_CREATION_SIGN_GRADE 145
#define SHRUBBERY_CREATION_EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE),
      target_("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE),
      target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE) {
  this->target_ = other.target_;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    this->target_ = other.target_;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!(AForm::isSign(this->getIsSign())))
    throw AForm::UnsignedException();
  else if (!(AForm::isExecute(this->getSignGrade(), this->getExecGrade())))
    throw AForm::GradeTooLowException();
  else
    this->executeAction(executor);
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const {
  std::string fileName = this->target_ + "_shrubbery";
  std::cout << fileName << " file created by " << executor.getName()
            << std::endl;
  std::ofstream outputFile(fileName);
  if (outputFile.fail()) {
    std::cerr << "Error: faild to create " << fileName << std::endl;
  }
  outputFile << "          .     .  .      +     .      .          .\n"
              "     .       .      .     #       .           .\n"
              "        .      .         ###            .      .      .\n"
              "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
              "          .      . \"####\"###\"####\"  .\n"
              "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
              "  .             \"#########\"#########\"        .        .\n"
              "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
              "     .     .  \"#######\"##\"##\"#######\"                  .\n"
              "                .\"##\"#####\"#####\"##\"           .      .\n"
              "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
              "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
              "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
              "            .     \"      000      \"    .     .\n"
              "       .         .   .   000     .        .       .\n"
              ".. .. ..................O000O........................ ...... ...\n";
  outputFile.close();
}
