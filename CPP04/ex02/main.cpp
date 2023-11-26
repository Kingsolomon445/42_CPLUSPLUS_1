#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    const Animal* animal[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
        // std::cout << std::endl;
        // std::cout << std::endl;
    }
    dynamic_cast<Dog*>(const_cast<Animal*>(animal[3]))->getBrain()->setIdea("You get luckier if best prepared!", 0);
    dynamic_cast<Cat*>(const_cast<Animal*>(animal[4]))->getBrain()->setIdea("My family(Cat family) is one of the most sucessful animals on planet!", 0);
    const Dog *dog = new Dog(*(dynamic_cast<Dog*>(const_cast<Animal*>(animal[3]))));
    const Cat *cat = new Cat(*(dynamic_cast<Cat*>(const_cast<Animal*>(animal[4]))));
    // Dog dog2(*dog);
    // Cat cat2(*cat);
    Dog dog2;
    Cat cat2;
    dog2 = *dog;
    cat2 = *cat;
    std::cout << "dog first idea: " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat first idea: " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 first idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 first idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Destructing all array objects!" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete animal[i];
    }
    // delete dog;
    // delete cat;
    std::cout << "Finished destruction!" <<  std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    dog->getBrain()->setIdea("I just changed my idea (DOG)", 0);
    cat->getBrain()->setIdea("I just changed my idea (CAT)", 0);
    std::cout << "dog first idea: " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "cat first idea: " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 first idea: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat2 first idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    


    return 0;
}