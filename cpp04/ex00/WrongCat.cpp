#include "WrongCat.hpp"

WrongCat::WrongCat() { 
    std::cout << "The default WrongCat constructor was called\n";
    type = "WrongCat";
    }
WrongCat::~WrongCat() { std::cout << "The default destructor was called\n";}
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) { *this = other;}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "Meaow Meaow...\n";
}