#include "ScavTrap.hpp"

ScavTrap::ScavTrap()  : ClapTrap("Deafault", 100, 50, 20)
{
    std::cout << "The  default ScavTrap constructor was called\n";
}

ScavTrap::ScavTrap(std::string ScavName) : ClapTrap(ScavName, 100, 50, 20)
{
    std::cout << "The ScavTrap constructor was called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "The ScavTrap destructor was called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) :  ClapTrap(other)
{
    std::cout << "The ScavTrap copy constructor was called" << std::endl;
    name = other.name;
    hitPoint = other.hitPoint;
    energyPoint = other.energyPoint;
    attackDamage = other.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "The ScavTrap copy assigment constructor was called" << std::endl;
       if (this != &other)
       {
            name = other.name;
            hitPoint = other.hitPoint;
            energyPoint = other.energyPoint;
            attackDamage = other.attackDamage;
       }
       return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoint == 0 || energyPoint == 0)
        std::cout << name << " cannot attack! No energy or hit points left." << std::endl;
     else
    {
        energyPoint--;
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
                  << attackDamage << " points of damage!" << std::endl;
    }
}