#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureacrat a("ali", 1);
        std::cout << a ;
        Bureacrat c("lilo", 2);
        c.incrementGrade();
        c.incrementGrade();
        std::cout << a;

    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}