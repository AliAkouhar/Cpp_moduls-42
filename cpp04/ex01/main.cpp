#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // int size = 4;
    // Animal*  animals[size];
    // for (int i = 0; i < size; i++)
    // {
    //     if (i % 2 == 0)
    //         animals[i] = new Cat;
    //     else
    //         animals[i] = new Dog;
    // }
    // for ( int i = 0; i < size ; i++)
    // {
    //     animals[i]->makeSound();
    //     delete animals[i];
    // }
    std::cout << "## DEEP COPY VS SHALLOW COPY ##\n\n";
    Cat c1;
    Cat c2(c1);
    std::cout << c1.getBrain(0) << std::endl;
    std::cout << c2.getBrain(0) << std::endl;
    c1.setBrain("cat", 0);
    std::cout << c1.getBrain(0) << std::endl;
    std::cout << c2.getBrain(0) << std::endl;
}