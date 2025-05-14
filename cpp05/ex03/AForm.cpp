#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradToSign(10), _gradToexecute(15){}

AForm::AForm(std::string name, int gradToSign, int gradToexecute) : _name(name), _isSigned(false), _gradToSign(gradToSign), _gradToexecute(gradToexecute)
{
    if (_gradToexecute < 1 || _gradToSign < 1)
        throw GradeTooHighException();
    else if (_gradToexecute > 150 || _gradToSign > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradToSign(other._gradToSign), _gradToexecute(other._gradToexecute) 
{
    if (_gradToexecute < 1 || _gradToSign < 1)
        throw GradeTooHighException();
    else if (_gradToexecute > 150 || _gradToSign > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
        // _gradToexecute = other._gradToexecute; //! i cannot do that because those values are const
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grad is too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grad too low");
}

const char* AForm::GradeSignException::what() const throw()
{
    return ("The form not signed");
}

const std::string& AForm::getName() const{
    return _name;
}

bool AForm::getSigned() const{
    return _isSigned;
}

int AForm::getGradToexec() const{
    return _gradToexecute;
}

int AForm::getGradTosign() const{
    return _gradToSign;
}

std::ostream& operator<<(std::ostream& out, AForm& form)
{
    out << "AForm name: " << form.getName() << std::endl;
    out << "is Signed: " << form.getSigned() << std::endl;
    out << "grad to execute is : " << form.getGradToexec() << std::endl;
    out << "grad to sign is : " << form.getGradTosign() << std::endl;
    return out;
}

void AForm::beSigned(const Bureacrat& b)
{
    if (b.getGrade() <= _gradToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}
