#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
private:
    std::string name;
public:
    void announce(void) const;
    Zombie(std::string ZombieName);
    ~Zombie();
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif