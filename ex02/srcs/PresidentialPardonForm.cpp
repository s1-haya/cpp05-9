#include "PresidentialPardonForm.hpp"

#define ROBOTOMY_REQUEST_SIGN_GRADE 25
#define ROBOTOMY_REQUEST_EXEC_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("default", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE) {}

PresidentialPardonForm::~PresidentialPardonForm() {}
