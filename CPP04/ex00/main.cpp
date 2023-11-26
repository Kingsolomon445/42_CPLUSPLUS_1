#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
    delete meta;
    delete i;
    delete j;
    std::cout << std::endl;
    std::cout << std::endl;

    const WrongAnimal* meta3 = new WrongAnimal();
    const WrongAnimal* i3 = new WrongCat();
    std::cout << i3->getType() << " " << std::endl;
    std::cout << meta3->getType() << " " << std::endl;
    i3->makeSound(); //will output the animal sound!
    meta3->makeSound();
    delete meta3;
    delete i3;
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
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}