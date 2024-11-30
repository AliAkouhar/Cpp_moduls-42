#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(4, 0);
    Point C(0, 3);
    Point P(0, 1.5);

    if (bsp(A, B, C, P))
        std::cout << "This point is included\n";
    else
        std::cout << "This point is exluded\n";
}