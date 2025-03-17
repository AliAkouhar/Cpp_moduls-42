#include "Point.hpp"
                             //x1            y2            y3
Fixed CalculSurface(Point const x, Point const y, Point const z)
{
    Fixed S;
    const Fixed x1 = x.getX();
    const Fixed y1 = x.getY();
    const Fixed x2 = y.getX();
    const Fixed y2 = y.getY();
    const Fixed x3 = z.getX();
    const Fixed y3 = z.getY();

    S = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/ Fixed(2);
    S = (S < Fixed(0)) ? (S * Fixed(-1)) : S;
    return (S);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed Sabp;
    Fixed Sacp;
    Fixed Scbp;
    Fixed Sabc;
    Sabc = CalculSurface(a, b, c);
    Sabp = CalculSurface(a, b, point);
    Sacp = CalculSurface(a, c, point);
    Scbp = CalculSurface(c, b, point);

    if (Sabc == 0 || Sabp == 0 || Sacp == 0 || Scbp == 0)
        return (false);
    if (Sabc == (Sabp + Sacp + Scbp))
        return (true);
    return (false);
}