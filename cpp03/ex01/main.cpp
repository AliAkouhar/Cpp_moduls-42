#include "ScavTrap.hpp"

int main()
{
    ClapTrap first("firstClap");

    first.Displaystate();
    // first.attack("ali");
    // first.beRepaired(20);
    ScavTrap second("hi");
    second.Displaystate();
    second.attack("ali");
    // second.beRepaired(30);
}