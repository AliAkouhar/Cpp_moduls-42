#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include <cstdlib>
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    AMateria* tmp1;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
    tmp = src->createMateria("cure");
    // std::cout << tmp << std::endl;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(1);
    me->equip(tmp);
    me->use(0, *bob);
    me->use(1, *bob);
    bob->equip(tmp1);
    bob->use(0, *me);
    bob->use(3, *me);
    delete bob;
    delete me;
    delete src;
    return 0;
}