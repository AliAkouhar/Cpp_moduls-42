#include "Bureacrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
int main()
{ 
    std::cout << "******************SHRUBBERY****************\n";
    try {
        Bureacrat b("ali", 1);
        ShrubberyCreationForm ber("home");
        std::cout << b;
        b.signForm(ber);
        std::cout << ber;
        b.executeForm(ber);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "******************ROBOTMY****************\n";
    try{
        Bureacrat c("hmo", 3);
        RobotomyRequestForm robo("robo");
        std::cout << c;
        std::cout << robo;
        c.signForm(robo);
        srand(time(NULL));
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
     }
    catch(std::exception& e)
    {
        std::cout << e.what();
    }
    std::cout << "******************PRESIDENTIAL****************\n";
    try{
        Bureacrat d("moha", 2);
        PresidentialPardonForm pres("pres");
        std::cout << d;
        d.signForm(pres);
        std::cout << pres;
        d.executeForm(pres);
    }
    catch(std::exception& e)
    {
        std::cout << e.what();
    }
}