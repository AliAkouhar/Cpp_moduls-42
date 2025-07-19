#include "iter.hpp"

int main()
{
    std::cout << "---------Test with int array---------" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, func<int>);
    std::cout << "---------Test with char array---------" << std::endl;
    char arr1[] = {'a', 'b', 'c', 'd', 'e'};
    iter(arr1, 5, func<char>);
}