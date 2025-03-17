#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap first("firstClap");
    first.Displaystate();
    // first.attack("ali");
    // first.takeDamage(5);
    // first.beRepaired(20);
    ScavTrap second("hi");
    second.Displaystate();
    second.attack("ali");
    // second.takeDamage(5);
    // second.beRepaired(30);
    FragTrap frag("frag");
    frag.Displaystate();
    frag.attack("Clap");
    // frag.takeDamage(5);
    // frag.beRepaired(20);
}