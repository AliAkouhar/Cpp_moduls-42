#include "Garbage.hpp"

Garbage::Garbage()
{
    next = NULL;
}

Garbage::Garbage(AMateria* adr) //? for the first time
{
    this->addr = adr;
    this->next = NULL;
}

Garbage::Garbage(AMateria* adr, Garbage* next)
{
    this->addr = adr;
    this->next = next;
}

Garbage::~Garbage(){
    delete addr;
}