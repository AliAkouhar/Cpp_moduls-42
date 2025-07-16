#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "utils.hpp"

Base* generate(void)
{
    int i;
    srand(time(NULL));
    i = rand();
    if (i % 2 == 0)
    {
        std::cout << "Generating an object of type A" << std::endl;
        return new A();
    }
    else if (i % 3 == 0)
    {
        std::cout << "Generating an object of type B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generating an object of type C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "The type of the object is A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "The type of the object is B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "The type of the object is C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void idnetify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "The type of the object is A" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "The type of the object is B" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "The type of the object is C" << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
    }
    std::cout << "Unkown type" << std::endl;   
}