#include "Array.hpp"

int main()
{

    Array<int> arr(5);
    Array<float> arr2(6);
    for (unsigned int i = 0; i < 6; i++)
        std::cout << arr2[i] << std::endl;
    int *numbers = new int;
    std::cout << *numbers << std::endl;
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    {
        Array<int> arr2 = arr;
        Array<int> arr3(arr2);
    }
    try{
        arr[6] = 1337;
    }
    catch (const Array<int>::outOfBounds& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << arr[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }
    try
    {
        arr[-2] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }
    
}