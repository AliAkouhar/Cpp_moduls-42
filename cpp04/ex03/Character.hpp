#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Garbage.hpp"

class Character : public ICharacter{
    private:
        std::string _name;
        AMateria* inventory[4];
        static Garbage* collect;
        static Garbage* tmp_collect;
        static int count;
    public:
        Character(std::string name);
        ~Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void free_collector();
        int check_garbage(Garbage *list, AMateria* adr);
        int checkMateria(Garbage **tmp, AMateria* adr);

};

#endif