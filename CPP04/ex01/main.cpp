#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* animal[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
        std::cout << std::endl;
        std::cout << std::endl;
    }
    dynamic_cast<Dog&>(*(static_cast<Animal*>(const_cast<void*>(static_cast<const void*>(animal[3]))))).getBrain()->setIdea("You get luckier if best prepared!", 0);
    dynamic_cast<Cat&>(*(static_cast<Animal*>(const_cast<void*>(static_cast<const void*>(animal[4]))))).getBrain()->setIdea("My family(Cat family) is one of the most sucessful animals on planet!", 0);
    Dog dog = dynamic_cast<Dog&>(*(static_cast<Animal*>(const_cast<void*>(static_cast<const void*>(animal[3])))));
    Cat cat = dynamic_cast<Cat&>(*(static_cast<Animal*>(const_cast<void*>(static_cast<const void*>(animal[4])))));
    std::cout << "dog first idea: " << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat first idea: " << cat.getBrain()->getIdea(0) << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete animal[i];
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << "dog first idea: " << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << "cat first idea: " << cat.getBrain()->getIdea(0) << std::endl;
    return 0;
}