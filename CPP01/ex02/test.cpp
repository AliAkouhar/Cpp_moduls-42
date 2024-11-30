// C++ Program to demonstrate 
// use of references
#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    // ref is a reference to x.
    int& ref = x;

    // Value of x is now changed to 20
    ref = 20;
    cout << "x = " << x << '\n';

    // Value of x is now changed to 30
    x = 30;
    int *ptr;
    int *p;

    ptr = &x;
    p = &ref;
    cout << "p holdes this address-->" << p << endl;
    *p = 100;
    *ptr = 200;
    cout << "ptr holde this adress-->" << ptr << endl;
    cout << "the address of x is-->  " << &x << endl;
    cout << "the address of x is-->  " << &ref << endl;
    cout << "ref = " << ref << '\n';

    return 0;
}
