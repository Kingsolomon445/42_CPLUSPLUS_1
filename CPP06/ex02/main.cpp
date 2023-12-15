#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *randPtr = generate();
    Base &a = *(new A());
    Base &b = *(new B());
    Base &c = *(new C());

    identify(randPtr);
    identify(a);
    identify(b);
    identify(c);

    delete randPtr;
    delete &a;
    delete &b;
    delete &c;
    return (0);
}