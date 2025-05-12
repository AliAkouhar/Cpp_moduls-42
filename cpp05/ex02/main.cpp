#include "Bureacrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
int main()
{ 
    //check the initialization list of all forms and then creacte the main function and go to final exercice
    // std::cout << "******************SHRUBBERY****************\n";
    // try {
    //     Bureacrat b("ali", 10);
    //     ShrubberyCreationForm ber("home");
    //     std::cout << b;
    //     std::cout << ber;
    //     b.executeForm(ber);
    // }
    // catch (std::exception& e)
    // {
    //     std::cout << e.what();
    // }
    std::cout << "******************ROBOTMY****************\n";
    try{
        Bureacrat c("hmo", 3);
        RobotomyRequestForm robo("robo");
        std::cout << c;
        std::cout << robo;
        c.signForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        c.executeForm(robo);
        
    }
    catch(std::exception& e)
    {
        std::cout << e.what();
    }
    //     Bureacrat a("ali", 1);
    //     std::cout << a ;
    //     Bureacrat c("lilo", 2);
    //     c.incrementGrade();
    //     c.incrementGrade();
    //     std::cout << a;

    // }
    // catch(std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}