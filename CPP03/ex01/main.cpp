#include "ScavTrap.hpp"

int main()
{
    ClapTrap first("firstClap");

    first.attack("ali");
    first.beRepaired(20);
    first.Displaystate();
    ScavTrap second("hi");
    second.attack("ali");
    second.beRepaired(30);
    second.Displaystate();
}