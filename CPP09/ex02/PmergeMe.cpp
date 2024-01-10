#include "PmergeMe.hpp"

std::vector<int> myVec;
std::deque<int> myDeque;
double dequeMilliSec;
double vecMilliSec;
int K;


PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other)
{
    *this = other;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
    if (this != &other) {}

    return *this;
}


// STATIC STARTER FUNCTIONS
void PmergeMe::parseArg(std::vector<std::vector<int> >  & myVec, std::deque<std::deque<int> > & myDeque, char *argv[])
{
    int i = 1;
    std::vector<int> pairVec;
    std::deque<int> pairDeque;

    while(argv[i])
    {
        int no;
        std::stringstream ss(argv[i]);
        ss >> no;
        pairVec.push_back(no);
        pairDeque.push_back(no);
        if (pairVec.size() == 2)
        {
            if (pairVec[0] < pairVec[1])
            {
                std::swap(pairVec[0], pairVec[1]);
                std::swap(pairDeque[0], pairDeque[1]);
            }
            myVec.push_back(pairVec);
            myDeque.push_back(pairDeque);
            pairVec.clear();
            pairDeque.clear();
        }
        i++;
    }
    if (!pairVec.empty())
    {
        myVec.push_back(pairVec);
        myDeque.push_back(pairDeque);
    }
    std::cout << "printing the vector pairs before sorting....." << std::endl;
    for (std::vector<std::vector<int> >::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        std::cout << (*it)[0] << "  " << (*it)[1] << std::endl;
    }
    std::cout << "printing the deque pairs before sorting ....." << std::endl;
    for (std::deque<std::deque<int> >::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << (*it)[0] << "  " << (*it)[1] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void PmergeMe::checkArg(char *argv[])
{
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < 48 || argv[i][j] > 57)
                throw std::runtime_error("Error");
            j++;
        }
        i++;
    }
}

// static int isVectorPairSorted(std::vector<std::vector<int> > & myVec)
// {
//     std::vector<std::vector<int> > sortedVec(myVec);
//     std::sort(sortedVec.begin(), sortedVec.end());
//     std::vector<std::vector<int> >::iterator myVecIt = myVec.begin();
//     std::vector<std::vector<int> >::iterator sortedVecIt = sortedVec.begin();
//     for (int i = 0; i < (int)myVec.size(); i++)
//     {
//         if (*sortedVecIt != *myVecIt)
//             return 0;
//         sortedVecIt++;
//         myVecIt++;
//     }
//     return 1;
// }
// static int isDequePairSorted(std::deque<std::deque<int> > & myDeque)
// {
//     std::deque<std::deque<int> > sortedDeque(myDeque);
//     std::sort(sortedDeque.begin(), sortedDeque.end());
//     std::deque<std::deque<int> >::iterator myDequeIt = myDeque.begin();
//     std::deque<std::deque<int> >::iterator sortedDequeIt = sortedDeque.begin();
//     for (int i = 0; i < (int)myDeque.size(); i++)
//     {
//         if (*sortedDequeIt != *myDequeIt)
//             return 0;
//         sortedDequeIt++;
//         myDequeIt++;
//     }
//     return 1;
// }


void PmergeMe::sortVectorPairs(std::vector<std::vector<int> > & myVec)
{
    for (int i = 0; i < (int)myVec.size(); i++)
    {
        std::vector<int> tmpVec(myVec[i + 1]);
        int j = i + 1;
        while (j > 0 && myVec[j - 1] > tmpVec)
        {
            myVec[j] = myVec[j - 1];
            j--;
        }
        myVec[j] = tmpVec;
    }
    std::cout << "printing the vector pairs after sorting....." << std::endl;
    for (std::vector<std::vector<int> >::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        std::cout << (*it)[0] << "  " << (*it)[1] << std::endl;
    }
}

void PmergeMe::sortDequePairs(std::deque<std::deque<int> > & myDeque)
{
    for (int i = 0; i < (int)myDeque.size(); i++)
    {
        std::deque<int> tmpDeque(myDeque[i + 1]);
        int j = i + 1;
        while (j > 0 && myDeque[j - 1] > tmpDeque)
        {
            myDeque[j] = myDeque[j - 1];
            j--;
        }
        myDeque[j] = tmpDeque;
    }
    std::cout << "printing the deque pairs after sorting ....." << std::endl;
    for (std::deque<std::deque<int> >::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << (*it)[0] << "  " << (*it)[1] << std::endl;
    }
}
