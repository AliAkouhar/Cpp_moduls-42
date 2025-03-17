#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
delete j;
delete i;
delete meta;
std::cout << "-----------\n";
const WrongAnimal* c = new WrongCat();
std::cout << c->getType() << " " << std::endl;
c->makeSound();
delete c;
return 0;
}