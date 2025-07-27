#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class NotfoundException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Value not found in the container";
        }
};
template <typename T>
int easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return std::distance(container.begin(), it);
    throw NotfoundException();
}


#endif