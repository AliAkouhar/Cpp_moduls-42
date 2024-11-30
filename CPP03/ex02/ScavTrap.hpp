#ifndef SCAVTRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
    ScavTrap();
    ScavTrap(std::string ScavName);
    ~ScavTrap();
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    void gaurdGate();
};

#endif