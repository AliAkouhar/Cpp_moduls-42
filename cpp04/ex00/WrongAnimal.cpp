#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {std::cout << "The WrongAnimal default constructor was called\n";}

WrongAnimal::~WrongAnimal() { std::cout << "The WrongAnimal destructor was called\n";}

WrongAnimal::WrongAnimal(std::string _type) : type(_type){}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
    *this = other;
}

std::string WrongAnimal::getType() const {return type;}

void WrongAnimal::makeSound() const{
    std::cout << "The WrongAnimal makesound\n";
}

