#include "Bureacrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
int main()
{ 
    try {
        Intern intern;
        AForm *form;
        form = intern.makeForm(" request", "ali");
        if (form)
        {
            std::cout << "the form has been created successfully" << std::endl;
            delete form;
        }
    }
    catch(std::exception& e)
    {
        std::cout << e.what();
    }
}