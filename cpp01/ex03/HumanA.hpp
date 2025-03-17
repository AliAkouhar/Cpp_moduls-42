#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    private:
        Weapon& WeaponA;
        std::string name;
    public:
        HumanA(const std::string& nameA, Weapon& obj); //constractor that takes a name for humanA
        void attack();
};

#endif