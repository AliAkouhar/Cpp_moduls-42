#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "The Default Animal constructor was called\n";
}

Animal::Animal(std::string _type) : type(_type)
{
    std::cout << "The paramiterazed constructor was called\n";
}

Animal::~Animal()
{
    std::cout << "The Animal destructor was called\n";
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type= other.type;
    return (*this);
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

void Animal::makeSound(void) const
{
    std::cout << "The animal makes sound\n";
}

std::string Animal::getType( void ) const {return (type);}

void Animal::setType(std::string _type)
{
    type = _type;
}
