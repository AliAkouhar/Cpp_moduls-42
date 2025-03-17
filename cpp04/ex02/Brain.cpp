#include "Brain.hpp"

Brain::Brain()
{
    for(int i = 0; i < 100; i++)
        ideas[i] = "brain";
    std::cout << "The default Brain constructor was called\n";
}

Brain::~Brain(){ std::cout << "The Destructor was called\n";}

Brain::Brain(const Brain& other)
{
    std::cout << "The Brain copy constructor was called\n";
    for (int i = 0; i < 100 ; i++)
        this->ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "The Brain copy assignement constructor was called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100 ; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::setIdea(std::string _idea, int index)
{
    ideas[index] = _idea;
}

std::string Brain::getIdea(int index)
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}