#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* catBrain;
    public:
        Cat();
        Cat(std::string _type);
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void makeSound() const;
        void setBrain(std::string idea, int index);
        std::string getBrain(int index);
};

#endif