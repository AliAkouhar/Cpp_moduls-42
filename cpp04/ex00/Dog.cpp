#include "Dog.hpp"

Dog::Dog() { 
    std::cout << "The default Dog constructor was called\n";
    type = "Dog";
    }
Dog::~Dog() { std::cout << "The default destructor was called\n";}
Dog::Dog(const Dog& other) : Animal(other) { *this = other;}
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Brak Brak...\n";
}