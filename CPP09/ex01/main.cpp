#include "RPN.hpp"

int main(int argc, char *argv[])
{
    std::list<int> operands;
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments!";
        return 1;
    }
    try
    {
        RPN::sortOps(operands, argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}