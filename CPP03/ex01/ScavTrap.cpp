#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "The  default ScavTrap constructor was called\n";
    name = "Default";
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string ScavName)
{
    std::cout << "The ScavTrap constructor was called\n";
    name = ScavName;
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
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

void ScavTrap::gaurdGate()
{
    std::cout << name << " is now in Gate keeper mode." << std::endl;
}