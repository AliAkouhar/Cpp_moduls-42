#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}