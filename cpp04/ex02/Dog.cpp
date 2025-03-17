#include "Dog.hpp"

Dog::Dog()
{ 
    std::cout << "The default Dog constructor was called\n";
    type = "Dog";
    dogBrain = new Brain;
}
Dog::~Dog() 
{
    delete dogBrain;
    std::cout << "The default destructor was called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
     *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        dogBrain = new Brain(*other.dogBrain);
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Brak Brak...\n";
}

std::string Dog::getBrain(int index)
{
    if (index >= 0 && index < 100)
        return dogBrain->getIdea(index);
    return NULL;
}

void Dog::setBrain(std::string _idea, int index)
{
    if (index >= 0 && index < 100)
        dogBrain->setIdea(_idea, index);
}