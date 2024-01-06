#include "RPN.hpp"

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments!";
        return 1;
    }
    sortOps(argv[1]);
    return 0;
}