#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) , _target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::robotAction() const{
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized sucssufuly\n";
    else
        std::cout << "The robot has been failed\n";
}

void RobotomyRequestForm::execute(Bureacrat const & executor) const{
    if (getSigned() && executor.getGrade() <= getGradToexec())
        robotAction();
    else if (!getSigned())
        throw GradeSignException();
    else
        throw GradeTooLowException();
}