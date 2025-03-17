#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Animal* i = new Cat();
    i->makeSound();
    // Animal n;
    // n.makeSound();
    delete i;
}



