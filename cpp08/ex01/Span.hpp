#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <limits>


class Span
{
    private:
        unsigned int _n;
        std::vector<int> _span;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class SizeException : public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif