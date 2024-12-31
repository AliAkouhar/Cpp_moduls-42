#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap first("firstClap");
    first.attack("ali");
    first.takeDamage(5);
    first.beRepaired(20);
    first.Displaystate();
    ScavTrap second("hi");
    second.attack("ali");
    second.takeDamage(5);
    second.beRepaired(30);
    second.Displaystate();
    FragTrap frag(frag);
    frag.attack("Clap");
    frag.takeDamage(5);
    frag.beRepaired(20);
    frag.Displaystate();
}