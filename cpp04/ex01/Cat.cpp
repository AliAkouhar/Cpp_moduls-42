#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    catBrain = new Brain;
    std::cout << "The Default Cat constructor was called\n";
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << "The Cat Destructor was called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        *this->catBrain = *other.catBrain;
    }
    return (*this);
}

Cat::Cat(const Cat& other) : Animal(other)
{
    *this = other;
}

void Cat::makeSound() const
{
    std::cout << "moaw moaw...\n";
}

void Cat::setBrain(std::string idea, int index)
{
    catBrain->setIdea(idea, index);
}

std::string Cat::getBrain(int index)
{
    return (catBrain->getIdea(index));
}