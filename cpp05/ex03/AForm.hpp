#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Bureacrat.hpp"


class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int  _gradToSign;
        const int _gradToexecute;
    public:
        AForm();
        AForm(std::string name, int gradToSign, int gradToexecute);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeSignException : public std::exception{
            public:
                const char* what() const throw();
        };
        const std::string& getName() const;
        bool getSigned() const;
        int getGradToexec() const;
        int getGradTosign() const;

        void beSigned(const Bureacrat& b);

        virtual void execute(Bureacrat const & executor) const = 0;

};

std::ostream& operator<<(std::ostream& out, AForm& form);
 
#endif