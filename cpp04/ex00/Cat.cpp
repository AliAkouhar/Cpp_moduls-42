#include "Cat.hpp"

Cat::Cat() { 
    std::cout << "The default Cat constructor was called\n";
    type = "Cat";
    }
Cat::~Cat() { std::cout << "The default destructor was called\n";}
Cat::Cat(const Cat& other) : Animal(other) { *this = other;}
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meaow Meaow...\n";
}