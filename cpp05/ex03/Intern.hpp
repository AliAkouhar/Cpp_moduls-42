#ifndef INTERN_HPP
#define ITERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target);
        class ErrMsg : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif