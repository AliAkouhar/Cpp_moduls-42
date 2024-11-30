#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "the default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "The constructor initialize the name" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "The destructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    name = other.name;
    attackDamage = other.attackDamage;
    energyPoint = other.energyPoint;
    hitPoint = other.hitPoint;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        attackDamage = other.attackDamage;
        energyPoint = other.energyPoint;
        hitPoint = other.hitPoint;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoint == 0 || energyPoint == 0)
        std::cout << name << " cannot attack! No energy or hit points left." << std::endl;
     else
    {
        energyPoint--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
                  << attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoint -= amount;
    if (hitPoint < 0)
        hitPoint = 0;
    std::cout << name
    << " takes "
    << amount
    << " point of Damage! Remaining health pints "
    << hitPoint
    << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoint != 0 && energyPoint != 0)
    {
        energyPoint--;
        hitPoint += amount;
         std::cout << name << " repairs itself, restoring " << amount 
                   << " hit points! Current health: " << hitPoint << "." << std::endl;
    }
    else
        std::cout << name << " is unabel to repair itself" << std::endl;
}

void ClapTrap::Displaystate()
{
    std::cout << "HitPoint: " << hitPoint
              << " EnergyPoint: " << energyPoint
              << " DamagePoint: " << attackDamage << std::endl;
}