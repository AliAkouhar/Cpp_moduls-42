#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::vector<std::string> args;
    try
    {
        if (ac > 1)
        {
            for (int i = 1; i < ac; i++)
                args.push_back(av[i]);
            PmergeMe pm(parseArgs(args));
            pm.MergeInsertionSort();
        }
        else
            throw PmergeMe::InvalidArgumentException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}