#include <iostream>
#include <cctype>
#include <string>

std::string    capitalize(std::string str)
{
    std::string capitalizedStr("");
    for (int i = 0; i < (int)str.size() ; ++i)
        capitalizedStr.push_back(toupper(str[i]));
    return (capitalizedStr);
}

int main(int argc, char **argv)
{
        
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; ++i)
        std::cout << capitalize(argv[i]);
    std::cout << std::endl;
    return 0;
}