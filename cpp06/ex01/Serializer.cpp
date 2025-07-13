#include "Serializer.hpp"

Serializer::~Serializer() {}

uintptr_t Serializer::serislize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserislize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}