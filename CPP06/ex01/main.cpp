#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data *dt = new Data(5, 7);
    uintptr_t uitPtr;
    Data *dataPtr;

    std::cout << "x: " << dt->getX() << "   y: " << dt->getY() << std::endl;
    uitPtr = Serializer::serialize(dt);
    dataPtr = Serializer::deserialize(uitPtr);
    std::cout << "x: " << dataPtr->getX() << "   y: " << dataPtr->getY() << std::endl;

    return (0);
}