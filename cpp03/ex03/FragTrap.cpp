#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
    std::cout << "the FragTrap default constructor was called" << std::endl;
}

FragTrap::FragTrap(std::string fragName) : ClapTrap(fragName, 100, 100, 30)
{
    std::cout << "The FragTrap parameterized constructor was called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "The FragTrap destructor was called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "The FragTrap copy constructor was called" << std::endl;
    name = other.name;
    hitPoint = other.hitPoint;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "The FragTrap copy assigment constructor was called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoint = other.hitPoint;
        energyPoint = other.energyPoint;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "give me a high fives Guys!!" << std::endl;
}