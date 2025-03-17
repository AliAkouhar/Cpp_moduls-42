#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure(){}

Cure::Cure(const Cure& other)
{
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    (void)other;
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds * " << std::endl;
}

AMateria* Cure::clone() const{
    AMateria* obj = new Cure();
    return obj;
}