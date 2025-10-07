#include "RPN.hpp"

int main(int ac, char **av)
{
    std::string input;
    std::stack<int> stack;
    try
    {
        if (ac != 2)
            throw RPN::ArgumentError();
        std::istringstream ss(av[1]);
        while (ss >> input)
            RPN::calculate(input, stack);
        if (!stack.empty() && stack.size() == 1)
            std::cout << stack.top() << std::endl;
        else
            throw RPN::ArgumentError();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}