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
};
        std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif