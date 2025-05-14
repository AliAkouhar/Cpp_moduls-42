#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 37), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string tagret) : AForm("ShrubberyCreationForm", 25, 5), _target(tagret) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

const char* ShrubberyCreationForm::FileException::what() const throw()
{
    return ("Error while opening the file\n");
}

void ShrubberyCreationForm::shrubberyAction() const{
    std::string fileName = _target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());
    if (outfile.is_open())
        outfile << "      ^\n     ^^^\n    ^^^^^\n   ^^^^^^^\n     ||\n";
    else
        throw FileException();
}

void ShrubberyCreationForm::execute(Bureacrat const & executor) const{
    if (getSigned() && executor.getGrade() <= getGradToexec())
        shrubberyAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}

AForm* ShrubberyCreationForm::createForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}