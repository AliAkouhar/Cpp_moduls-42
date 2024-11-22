#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed{
    private:
        int fixNum;
        static const int n;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        Fixed(const int numInt);
        Fixed(const float numFloat);
        int getRawBits( void ) const;
        void setRawBits( int const raw ); 
        int toInt(void) const;
        float toFloat(void) const;
        /* COMPARAISON OPERATIONS */
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator>(const Fixed& other);
        bool operator>=(const Fixed& other);
        /* ARITHMITIC OPERATIONS */
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);
        /* PRE-POST INCREMENTATION */
        Fixed& operator++();
        Fixed operator++(int);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);

};
        std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif