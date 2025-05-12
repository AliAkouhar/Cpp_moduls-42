#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form{
    private:
        const std::string _name;
        bool _isSigned;
        const int  _gradToSign;
        const int _gradToexecute;
    public:
        Form();
        Form(std::string name, int gradToSign, int gradToexecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };

        const std::string& getName() const;
        bool getSigned() const;
        int getGradToexec() const;
        int getGradTosign() const;

        void beSigned(const Bureacrat& b);

};

std::ostream& operator<<(std::ostream& out, Form& form);
 
#endif