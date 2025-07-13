#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>

#include <iostream>

struct Data{
    int x;
    char c;
};


class Serializer {
    public:
        ~Serializer();
        static uintptr_t serislize(Data *ptr);
        static Data *deserislize(uintptr_t raw);
};

#endif