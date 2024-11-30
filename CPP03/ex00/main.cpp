#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");
    clappy.Displaystate();
std::cout << "------------------\n";
    // Display initial state
    // std::cout << "Initial state:" << std::endl;
    clappy.attack("Enemy");
    clappy.takeDamage(4);
    clappy.beRepaired(6);

    clappy.Displaystate();
    // Test edge cases
   /*  std::cout << "\nTesting edge cases:" << std::endl;
    clappy.takeDamage(20); // Reduce hit points to 0
    clappy.attack("Enemy");
    clappy.beRepaired(10); */

    ClapTrap backup = clappy; // Test copy constructor
    backup.attack("Another Enemy");

    return 0;
}
