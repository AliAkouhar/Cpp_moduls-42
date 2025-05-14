#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

const char* Intern::ErrMsg::what() const throw(){
    return "Form not found\n";
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    AForm* (*Forms[])(std::string) ={
        &ShrubberyCreationForm::createForm,
        &RobotomyRequestForm::createForm,
        &PresidentialPardonForm::createForm
    };
    std::string arrName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (arrName[i] == formName)
        {
            std::cout << "The intern create " << formName << std::endl;
            return Forms[i](target);
        }
    }
    throw ErrMsg();
    return NULL;
}