#ifndef EX00_BUREAUCRAT_HPP_
#define EX00_BUREAUCRAT_HPP_

#include <iostream>

#define MIN_GRADE 1
#define MAX_GRADE 150

class Bureaucrat{
private:
	const std::string name_;
	unsigned int grade_;

public:
	//Implement also two member functions to increment or decrement the bureaucrat grade
	void incrementGrade();
	void decrementGrade();
	const std::string getName() const;
	unsigned int getGrade() const;
	void setGrade(unsigned int grade);
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& data );

#endif
