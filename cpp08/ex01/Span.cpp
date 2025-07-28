#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n)
{
    _span.reserve(n);
}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        _span = other._span;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_span.size() >= _n)
        throw SizeException();
    _span.push_back(number);    
}

int Span::shortestSpan()
{
    if (_span.size() < 2)
        throw NoSpanException();
    std::vector<int> sortedSpan = _span;
    std::sort(sortedSpan.begin(), sortedSpan.end());
    int shortest = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = sortedSpan.begin(); it != sortedSpan.end() -1 ; it++)
    {
        int diff = *(it + 1) - *it;
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_span.size() < 2)
        throw NoSpanException();
    int min = *std::min_element(_span.begin(), _span.end());
    int max = *std::max_element(_span.begin(), _span.end());
    return max - min;
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _span.size() > _n)
        throw SizeException();
    _span.insert(_span.end(), begin, end);
}


const char* Span::NoSpanException::what() const throw()
{
    return "No span can be found";
}

const char* Span::SizeException::what() const throw()
{
    return "Cannot add more numbers than the span size";
}
