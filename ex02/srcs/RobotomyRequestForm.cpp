#include "RobotomyRequestForm.hpp"

#define ROBOTOMY_REQUEST_SIGN_GRADE 72
#define ROBOTOMY_REQUEST_EXEC_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default", ROBOTOMY_REQUEST_SIGN_GRADE,
            ROBOTOMY_REQUEST_EXEC_GRADE) {}

RobotomyRequestForm::~RobotomyRequestForm() {}
