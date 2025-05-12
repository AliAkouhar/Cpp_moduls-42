#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureacrat b("ali", 10);
        Form form("job", 9, 20);
        b.signForm(form);
        std::cout << "after signing " << std::endl;
        std::cout << b;
        std::cout << form;
    }
    catch (std::exception& e)
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