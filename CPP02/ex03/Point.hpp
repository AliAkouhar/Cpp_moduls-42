#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
class Point{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point(); //Default
        Point(const float a, const float b);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        const Fixed& getX() const;
        const Fixed& getY() const;
};

Fixed CalculSurface(Point const x, Point const y, Point const z);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif