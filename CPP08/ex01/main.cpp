#include "Span.hpp"
#include <iostream>

int main()
{
    try
    {
        Span sp = Span(4000);
        // sp.addRangeOfNumbers(10000, 100, 22000000);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(10);
        sp.addNumber(19);

        
        sp.printNumbers();
        sp.addNumber(100);
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}