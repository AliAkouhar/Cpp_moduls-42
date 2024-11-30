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
