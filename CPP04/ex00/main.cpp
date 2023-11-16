#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << std::endl;
    std::cout << std::endl;
    Animal meta2;
    Dog j2;
    Cat i2;
    std::cout << j2.getType() << " " << std::endl;
    std::cout << i2.getType() << " " << std::endl;
    std::cout << meta2.getType() << " " << std::endl;
    i2.makeSound(); //will output the cat sound!
    j2.makeSound();
    meta2.makeSound();
    delete meta;
    delete i;
    delete j;
    return 0;
}