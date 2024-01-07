#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::vector<int> intVec;

    intVec.push_back(7);
    intVec.push_back(10);
    intVec.push_back(3);
    intVec.push_back(23);
    intVec.push_back(9);
    
    try
    {
        ::easyfind(intVec, 10);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}