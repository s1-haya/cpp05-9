#include "ShrubberyCreationForm.hpp"

#include <fstream>

#include "AForm.hpp"

#define SHRUBBERY_CREATION_SIGN_GRADE 145
#define SHRUBBERY_CREATION_EXEC_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE),
      target_("target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE),
      target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("ShrubberyCreationForm", SHRUBBERY_CREATION_SIGN_GRADE,
            SHRUBBERY_CREATION_EXEC_GRADE),
      target_(other.target_ + "_copy") {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
  if (this != &other) {
    this->setIsSign(other.getIsSign());
    this->target_ = other.target_;
  }
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!(AForm::isSign(this->getIsSign())))
    throw AForm::UnsignedException();
  else if (!(AForm::isExecute(executor.getGrade())))
    throw AForm::GradeTooLowException();
  else
    this->executeAction(executor);
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const {
  std::string fileName = this->target_ + "_shrubbery";
  std::ofstream outputFile(fileName.c_str());
  if (outputFile.fail()) {
    std::cerr << "Error: faild to create " << fileName << std::endl;
    return;
    std::cout << fileName << " file created by " << executor.getName()
              << std::endl;
  }

  outputFile
      << "          .     .  .      +     .      .          .\n"
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

const std::string& ShrubberyCreationForm::getTarget() const {
  return (this->target_);
}
