#include "ShrubberyCreationForm.hpp"
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

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  try {
    AForm::checkExecute(this->getIsSign(), this->getSignGrade(),
                        this->getExecGrade());
    this->action(executor);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}
void ShrubberyCreationForm::action(Bureaucrat const &executor) const {
  std::string fileName = this->target_ + "_shrubbery";
  std::cout << fileName << " file created by " << executor.getName()
            << std::endl;
  std::ofstream outputFile(fileName);
  outputFile << "writes ASCII trees";
  outputFile.close();
  // std::cout << this->getName() << " signed by " << executor.getName()
  //           << std::endl;
}
