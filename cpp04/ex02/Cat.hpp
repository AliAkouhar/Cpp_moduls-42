#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    Brain* catBrain;
    public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    void makeSound() const;
    std::string getBrain(int index);
    void setBrain(std::string idea, int index);
};

#endif