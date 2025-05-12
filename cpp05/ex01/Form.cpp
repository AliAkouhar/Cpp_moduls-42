#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradToSign(10), _gradToexecute(15){}

Form::Form(std::string name, int gradToSign, int gradToexecute) : _name(name), _isSigned(false), _gradToSign(gradToSign), _gradToexecute(gradToexecute)
{
    if (_gradToexecute < 1 || _gradToSign < 1)
        throw GradeTooHighException();
    else if (_gradToexecute > 150 || _gradToSign > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradToSign(other._gradToSign), _gradToexecute(other._gradToexecute) 
{
    if (_gradToexecute < 1 || _gradToSign < 1)
        throw GradeTooHighException();
    else if (_gradToexecute > 150 || _gradToSign > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
        // _gradToexecute = other._gradToexecute; //! i cannot do that because those values are const
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grad is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grad too low");
}

const std::string& Form::getName() const{
    return _name;
}

bool Form::getSigned() const{
    return _isSigned;
}

int Form::getGradToexec() const{
    return _gradToexecute;
}

int Form::getGradTosign() const{
    return _gradToSign;
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "is Signed: " << form.getSigned() << std::endl;
    out << "grad to execute is : " << form.getGradToexec() << std::endl;
    out << "grad to sign is : " << form.getGradTosign() << std::endl;
    return out;
}

void Form::beSigned(const Bureacrat& b)
{
    if (b.getGrade() <= _gradToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}
