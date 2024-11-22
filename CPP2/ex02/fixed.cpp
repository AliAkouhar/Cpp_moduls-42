#include "Fixed.hpp"

const int Fixed::n = 8;

Fixed::Fixed() : fixNum(0){
    std::cout << "Default constructor called\n";
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    fixNum = other.fixNum;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixNum = other.fixNum;
    return *this;
}
Fixed::Fixed(const int numInt)
{
    std::cout << "Int constructor called" << std::endl;
    fixNum = numInt * (1 << 8);
}

Fixed::Fixed(const float numFloat)
{
    std::cout << "Float constructor called" << std::endl;
    fixNum = roundf(numFloat * (1 << n));
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixNum;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fixNum = raw;
}

int Fixed::toInt(void) const
{
    return (fixNum / (1 << 8));
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(fixNum) / (1 << 8));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
/* COMPARAISON OPERATIONS */

bool Fixed::operator==(const Fixed& other){return (fixNum == other.fixNum);}

bool Fixed::operator!=(const Fixed& other){return (fixNum != other.fixNum);}

bool Fixed::operator<(const Fixed& other){return (fixNum < other.fixNum);}

bool Fixed::operator<=(const Fixed& other){return (fixNum <= other.fixNum);}

bool Fixed::operator>(const Fixed& other){return (fixNum > other.getRawBits());}

bool Fixed::operator>=(const Fixed& other){return (fixNum >= other.fixNum);}

/* ARITHMITIQ OPERATIONS */

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed obj;

    obj.setRawBits(fixNum + other.fixNum);
    return (obj);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed obj;

    obj.setRawBits(fixNum - other.fixNum);
    return (obj);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed obj;

    obj.setRawBits((fixNum * other.fixNum) / (1 << n));
    return (obj);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed obj;

    obj.setRawBits((fixNum * (1 << n)) / other.fixNum);
    return (obj);
}

/* PRE-POST INCRIMENTATION */

Fixed& Fixed::operator++()
{
    ++fixNum;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;

    tmp = *this;
    ++fixNum;
    return (tmp);
}

/* MAX-MIN */

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}