#ifndef PRESIDENTIALPARDONFORM_hpp 
#define PRESIDENTIALPARDONFORM_hpp

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void presidentAction() const;
        void execute(Bureacrat const & executor) const;
};

#endif