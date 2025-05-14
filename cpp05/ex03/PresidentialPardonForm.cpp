#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other){
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::presidentAction() const{
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(Bureacrat const& executor) const{
    if (getSigned() && executor.getGrade() <= getGradToexec())
        presidentAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}

AForm* PresidentialPardonForm::createForm(std::string target)
{
    return new PresidentialPardonForm(target);
}