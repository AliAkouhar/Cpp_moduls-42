#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        ideas[i] = "Brain";
    std::cout << "The Default Brain constructor was called\n";
}

Brain::~Brain()
{
    std::cout << "The Brain desructor was called\n";
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::Brain(const Brain& other)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

std::string Brain::getIdea(int index)
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return ("");
}

void Brain::setIdea(std::string idea, int index)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}