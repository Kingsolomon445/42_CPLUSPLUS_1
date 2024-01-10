#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::vector<int> > myVec;
    std::deque<std::deque<int> > myDeque;

    if (argc < 1)
        return 1;
    try
    {
        PmergeMe::checkArg(argv);
        PmergeMe::parseArg(myVec, myDeque, argv);
        PmergeMe::sortVectorPairs(myVec);
        PmergeMe::sortDequePairs(myDeque);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
