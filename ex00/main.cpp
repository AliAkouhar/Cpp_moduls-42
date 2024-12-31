#include "ClapTrap.hpp"

int main() {
    ClapTrap clappy("Clappy");
std::cout << "------------------\n";
    // Display initial state
    // std::cout << "Initial state:" << std::endl;
    clappy.attack("Enemy");
    // clappy.takeDamage(4);
    // std::cout << "-----------------------------\n";
    // clappy.Displaystate();
    // std::cout << "-----------------------------\n";
    clappy.beRepaired(6);
    clappy.takeDamage(20); // Reduce hit points to 0
    clappy.attack("Enemy");
    clappy.beRepaired(10);
    // Test edge cases
   /*  std::cout << "\nTesting edge cases:" << std::endl;
     */

    ClapTrap backup = clappy; // Test copy constructor
    backup.attack("Another Enemy");

    return 0;
}
