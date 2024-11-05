#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <cstdlib>

class HumanB{
    private:
        Weapon* weaponB;
        std::string name;
    public:
        void setWeapon(Weapon& _weapon);
        HumanB(const std::string& nameB);
        void attack() const;
};

#endif