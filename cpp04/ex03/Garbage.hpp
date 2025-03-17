#ifndef GARBAGE_HPP
#define GARBAGE_HPP

#include "AMateria.hpp"

struct Garbage{
    AMateria* addr;
    Garbage* next;

    Garbage();
    Garbage(AMateria *adr);
    Garbage(AMateria* adr, Garbage* next);
    ~Garbage();
};

#endif