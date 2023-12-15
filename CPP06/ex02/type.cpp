#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *initA()
{
    return new A();
}
Base *initB()
{
    return new B();
}
Base *initC()
{
    return new C();
}

Base *generate(void)
{
    Base* (*initRandChild[3]) (void) = {&initA, &initB, &initC};
    int randNo;

    srand(time(NULL));
    randNo = rand() % 3;
    std::cout << "Random number: " << randNo << std::endl;
    return (*initRandChild[randNo])();
}

void identify(Base *p)
{  
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Type do not match any of: A, B, C." << std::endl;
}

void identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Type do not match any of: A, B, C." << std::endl;
    }
        
}
