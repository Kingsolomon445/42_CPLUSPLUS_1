#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer & other)
{
    static_cast<void>(other);
}

Serializer::~Serializer() {}

Serializer & Serializer::operator=(const Serializer & other)
{
    static_cast<void>(other);
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t uitPtr;

    uitPtr = reinterpret_cast<uintptr_t>(ptr);
    return uitPtr;
}
Data* Serializer::deserialize(uintptr_t raw)
{
    Data *dataPtr;

    dataPtr = reinterpret_cast<Data*>(raw);
    return dataPtr;
}