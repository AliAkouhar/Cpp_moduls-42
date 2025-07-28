#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack& other) {*this = other;}
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                this->c = other.c;
            return *this;
        }
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;

        iterator begin()
        {
            return this->c.begin();
        }
        const_iterator begin() const
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        const_iterator end() const
        {
            return this->c.end();
        }
};


#endif
