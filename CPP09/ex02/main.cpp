#include "PmergeMe.hpp"

static int toInt(std::string str)
{
    int no;
    std::stringstream ss(str);
    ss >> no;
    return no;
}

static void printUnsorted(std::vector<int> & unsorted)
{
    std::cout << "Before:  ";
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        std::cout << unsorted[i] << " ";
    }
    std::cout << std::endl;
}

static void evalArg(std::vector<int> & unsortedVec, std::deque<int> & unsortedDeque, char *argv[])
{
    int i = 1;
    while (argv[i])
    {
        int offset = 0;
        if (argv[i][offset] == '-' || argv[i][offset] == '+')
        {
            if (argv[i][offset] == '-')
                throw std::runtime_error("Error: '" + std::string(argv[i]) + "'");
            offset++;
        }
        std::string str = &argv[i][offset];
        int j = 0;
        if (!str[j])    
            throw std::runtime_error("Error: '" + str + "'");
        while (str[j])
        {
            if (str[j] < 48 || str[j] > 57)
                throw std::runtime_error("Error: '" + str + "'");
            j++;
        }
        unsortedVec.push_back(toInt(str));
        unsortedDeque.push_back(toInt(str));
        i++;
    }
    if (unsortedVec.empty())
        throw std::runtime_error("Error: empty argument!");
}

static void useVector(std::vector<std::vector<int> > myVec, std::vector<int> unsorted)
{
    std::vector<int> mainChainVec;
    clock_t startTime;
    clock_t endTime;
    double diffTime;
    startTime = clock();
    if (!PmergeMe::isVecSorted(unsorted))
    {
        PmergeMe::parseVectorArg(myVec, unsorted);
        PmergeMe::sortVectorPairs(myVec, 0, myVec.size() - 1);
        std::vector<int> pendVec;
        PmergeMe::createVectorMainChainAndPend(myVec, mainChainVec, pendVec);
        PmergeMe::insertionSortVector(mainChainVec, pendVec);
    }
    else
        mainChainVec = unsorted;
    endTime = clock();
    diffTime = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    PmergeMe::printSortedVec(mainChainVec);
    if (PmergeMe::isVecSorted(mainChainVec))
        std::cout << "Time to process a range of " << mainChainVec.size() << " elements with std::vector : " << diffTime << " ms" << std::endl;
}

static void useDeque(std::deque<std::deque<int> > myDeque, std::deque<int> unsorted)
{
    std::deque<int> mainChainDeque;
    clock_t startTime;
    clock_t endTime;
    double diffTime;
    startTime = clock();
    if (!PmergeMe::isDequeSorted(unsorted))
    {
        PmergeMe::parseDequeArg(myDeque,  unsorted);
        PmergeMe::sortDequePairs(myDeque, 0, myDeque.size() - 1);
        std::deque<int> pendDeque;
        PmergeMe::createDequeMainChainAndPend(myDeque, mainChainDeque, pendDeque);
        PmergeMe::insertionSortDeque(mainChainDeque, pendDeque);
    }
    else
        mainChainDeque = unsorted;
    endTime = clock();
    diffTime = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    if (PmergeMe::isDequeSorted(mainChainDeque))
        std::cout << "Time to process a range of " << mainChainDeque.size() << " elements with std::deque : " << diffTime << " ms" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc < 1)
        return 1;
    std::vector<std::vector<int> > myVec;
    std::vector<int>  unsortedVec;
    std::deque<int>  unsortedDeque;
    std::deque<std::deque<int> > myDeque;
    try
    {
        evalArg(unsortedVec, unsortedDeque, argv);
        printUnsorted(unsortedVec);
        useVector(myVec, unsortedVec);
        useDeque(myDeque, unsortedDeque);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
