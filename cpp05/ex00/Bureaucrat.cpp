#include "Bureaucrat.hpp"

Bureacrat::Bureacrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureacrat::~Bureacrat() {}

Bureacrat::Bureacrat(const Bureacrat& other) : _name(other._name), _grade(other._grade) {}

Bureacrat& Bureacrat::operator=(const Bureacrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

std::string Bureacrat::getName() const {return _name;}

int Bureacrat::getGrade() const {return _grade;}

void Bureacrat::incrementGrade()
{
    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
}

void Bureacrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}

const char* Bureacrat::GradeTooHighException::what() const throw()
{
    return ("the grade is too High");
}

const char* Bureacrat::GradeTooLowException::what() const throw()
{
    return ("the grade is too Low");
}

std::ostream& operator<<(std::ostream& out, const Bureacrat& b)
{
    out << b.getName() << ", bureacrat Grade " << b.getGrade() << "." << std::endl;
    return out;
}