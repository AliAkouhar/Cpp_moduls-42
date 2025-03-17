#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap	b("Morgan");
    
	b.whoAmI();
    b.Displaystate();
	std::cout << "===" << std::endl;
	b.takeDamage(3);
	b.takeDamage(20);
	b.beRepaired(3);
	b.attack("Eric");
	b.attack("Eric");
	b.attack("Eric");
	b.beRepaired(100);
	b.attack("Eric");
    b.guardGate();
    b.highFivesGuys();

    return 0;
}