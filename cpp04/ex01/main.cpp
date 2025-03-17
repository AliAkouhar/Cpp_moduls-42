#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Animal* animals[4];
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else    
            animals[i] = new Cat();
    }

    for (int i = 0; i < 4; i++)
         animals[i]->makeSound();
    for (int i = 0; i < 4; i++)
        delete animals[i];
     std::cout << "\n## DEEP COPY ##\n\n";
    Cat *cat = new Cat();
    Cat cat1(*cat);
    std::cout << cat->getBrain(0) << std::endl;
    std::cout << cat1.getBrain(0) << std::endl;
    cat->setBrain("heho", 0);
    std::cout << cat->getBrain(0) << std::endl;
    std::cout << cat1.getBrain(0) << std::endl;
    cat1.setBrain("hna", 120);
    delete cat;
    std::cout << cat1.getBrain(50) << std::endl;
}



