#include "PresidentialPardonForm.hpp"

#define PRESIDENTIAL_PARDON_SIGN_GRADE 25
#define PRESIDENTIAL_PARDON_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", PRESIDENTIAL_PARDON_SIGN_GRADE,
            PRESIDENTIAL_PARDON_EXEC_GRADE) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	std::cout << executor.getName() << std::endl;
}
