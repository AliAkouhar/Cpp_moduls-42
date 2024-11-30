#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const float a, const float b) : x(a) , y(b){}

Point::Point(const Point& other): x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
        std::cerr << "can not assigne this value\n";
    return (*this);
}

const Fixed& Point::getX() const {return (x);}

const Fixed& Point::getY() const {return (y);}