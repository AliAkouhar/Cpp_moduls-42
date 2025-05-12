#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

    class Bureacrat{
        private:
            const std::string _name;
            int _grade;
        public:
            Bureacrat(std::string name, int grade);
            Bureacrat(const Bureacrat& other);
            Bureacrat& operator=(const Bureacrat& other);
            ~Bureacrat();
            std::string getName() const;
            int getGrade() const;
            void incrementGrade();
            void decrementGrade();
            class GradeTooLowException : public std::exception{
                public:
                    const char* what() const throw();
            };
            class GradeTooHighException : public std::exception{
                public:
                    const char* what() const throw();
            };
    };
    std::ostream& operator<<(std::ostream& out, const Bureacrat& b);

#endif