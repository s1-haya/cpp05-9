#include "Bureaucrat.hpp"

void Bureaucrat::incrementGrade()
{
	try
	{
		if (MIN_GRADE <= this->grade_ && this->grade_ <= MAX_GRADE) 
			this->grade_ ++;
		else
			throw std::runtime_error("MAX GRADE!!");
	}
	catch (const std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
}
void decrementGrade();

const std::string Bureaucrat::getName() const
{
	return (this->name_);
}

unsigned int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void Bureaucrat::setGrade(unsigned int grade)
{
	this->grade_ = grade;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& data )
{
	os << "<name>, bureaucrat grade " << data.getGrade();
	return (os);
}
