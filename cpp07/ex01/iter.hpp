#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void func(T& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void iter(T* arr, size_t size, void (*func)(T&))
{
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
}

#endif
