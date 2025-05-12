#ifndef SHURBBERYCREATIONFORM_HPP
#define SHURBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void execute(Bureacrat const & executor) const ;
    void shrubberyAction() const;

    class FileException : public std::exception{
        public:
            const char* what() const throw();
    };
};

#endif