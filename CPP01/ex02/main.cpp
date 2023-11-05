#include <iostream>

int main(void)
{
    std::string stringVar = "HI THIS IS BRAIN";
    std::string *stringPtr = &stringVar;
    std::string &stringRef = stringVar;

    //Displaying Address
    std::cout << &stringVar << std::endl;
    std::cout << stringPtr << std::endl;
    std::cout << &stringRef << std::endl;

    //Displaying Content
    std::cout << stringVar << std::endl;
    std::cout << *stringPtr << std::endl;
    std::cout << stringRef << std::endl;

    return (0);
}