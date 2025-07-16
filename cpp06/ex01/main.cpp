#include "Serializer.hpp"

int main()
{
    Data *ptr1 = new Data();
    Data *ptr2;

    ptr1->x = 42;
    ptr1->c = 'a';
    uintptr_t raw = Serializer::serislize(ptr1);
    std::cout << "raw: " << raw << std::endl;
    std::cout << "---------PTR1!---------" << std::endl;
    std::cout << "x: " << ptr1->x << std::endl;
    std::cout << "c: " << ptr1->c << std::endl;
    ptr2 = Serializer::deserislize(raw);
    std::cout << "---------PTR2!---------" << std::endl;
    std::cout << "x: " << ptr2->x << std::endl;
    std::cout << "c: " << ptr2->c << std::endl;
    delete ptr1;
    return 0;
}