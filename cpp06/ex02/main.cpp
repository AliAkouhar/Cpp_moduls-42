#include "utils.hpp"

int main()
{
    Base* ptr = generate();
    std::cout << "Identify by pointer:" << std::endl;
    idnetify(*ptr);
    std::cout << "Identify by reference:" << std::endl;
    identify(ptr);
    delete ptr;
    return 0;
}