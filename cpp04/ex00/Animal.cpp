#include "Animal.hpp"

Animal::Animal() {std::cout << "The Animal default constructor was called\n";}

Animal::~Animal() { std::cout << "The Animal destructor was called\n";}

Animal::Animal(std::string _type) : type(_type){}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

Animal::Animal(const Animal& other){
    *this = other;
}

std::string Animal::getType() const {return type;}

void Animal::makeSound() const{
    std::cout << "The Animal makesound\n";
}

