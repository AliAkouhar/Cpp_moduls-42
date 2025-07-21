#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
    private:
        T* _array;
        unsigned int _n;
    public:
        Array() : _n(0)
        {
            _array = new T[_n];
        }
        Array(unsigned int n) : _n(n)
        {
            _array = new T[_n];
        }
        Array(const Array& other)
        {
            _n = other._n;
            _array = new T[_n];
            for (unsigned int i = 0; i < _n; i++)
                _array[i] = other._array[i];
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                _n = other._n;
                delete[] _array;
                _array = new T[_n];
                for (unsigned int i = 0; i < _n; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        }

        ~Array()
        {
            delete[] _array;
        }

        unsigned int size() const
        {
            return _n;
        }
        
        class outOfBounds : public std::exception {
            public:
                const char* what() const throw()
                {
                    return "Index out of bounds";
                }
        };

        T& operator[](unsigned int index)
        {
            if (index >= _n)
                throw outOfBounds();
            return _array[index];
        }
        const T& operator[](unsigned int index) const{
            if (index >= _n)
                throw outOfBounds();
            return _array[index];
        }
};

#endif