#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    try
    {
        int index = easyfind(vec, 10);
        std::cout << "Value found! at index " << index << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}