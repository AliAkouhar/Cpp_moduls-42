#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name", 100, 50, 30), name("Default")
{
    std::cout << "The DiamondTrap default constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), name(name)
{
    std::cout << "The parametirazed constructor was called\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "The DiamondTrap destructor was called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout << "The copy constructor was called\n";
    *this = other;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "The copy operator was called\n";
    if (this != &other)
    {
        ClapTrap::name = other.name + "_clap_name";
        name = other.name;
        attackDamage = other.attackDamage;
        energyPoint = other.energyPoint;
        hitPoint = other.hitPoint;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "my name is " << name << " , and my grandPa clapTrap's name is " << ClapTrap::name << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}