#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 1)
        return 1;
    try
    {
        checkArg(argv);
        parseArg(argv);
        printUnsorted();
        sortArg("vector");
        sortArg("deque");
        printSorted();
        printTimeTaken();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

// https://www.geeksforgeeks.org/sorting-by-combining-insertion-sort-and-merge-sort-algorithms/
// https://iq.opengenus.org/merge-insertion-sort/