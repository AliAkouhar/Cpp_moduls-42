#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* dogBrain;
    public:
        Dog();
        Dog(std::string _type);
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const;
        void setBrain(std::string idea, int index);
        std::string getBrain(int index);
};

#endif