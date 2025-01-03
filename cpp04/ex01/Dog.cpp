#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    dogBrain = new Brain;
    std::cout << "The Default Dog constructor was called\n";
}

Dog::~Dog()
{
    delete dogBrain;
    std::cout << "The Dog Destructor was called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        *this->dogBrain = *other.dogBrain;
    }
   return (*this); 
}

Dog::Dog(const Dog& other) : Animal(other)
{
    *this = other;
}

void Dog::makeSound() const
{
    std::cout << "hoaw hoaw...\n";
}

void Dog::setBrain(std::string idea, int index)
{
    dogBrain->setIdea(idea, index);
}

std::string Dog::getBrain(int index)
{
    return (dogBrain->getIdea(index));
}