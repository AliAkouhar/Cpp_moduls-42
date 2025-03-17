#include "Cat.hpp"

Cat::Cat() 
{ 
    type = "Cat";
    catBrain = new Brain;
    std::cout << "The default Cat constructor was called\n";
}
Cat::~Cat()
{
    delete catBrain;
    std::cout << "The default destructor was called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
     *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meaow Meaow...\n";
}

std::string Cat::getBrain(int index)
{
    if (index >= 0 && index < 100)
        return catBrain->getIdea(index);
    return NULL;
}

void Cat::setBrain(std::string _idea, int index)
{
    if (index >= 0 && index < 100)
        catBrain->setIdea(_idea, index);
}