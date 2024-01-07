#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <vector>

template <typename T>
void easyfind(T hayStack, int needle)
{
    if (find(hayStack.begin(), hayStack.end(), needle) == hayStack.end())
        throw std::out_of_range("Not Found!");
    std::cout << "Element: " << needle << " found!" << std::endl;
}
#endif