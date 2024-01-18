#include "PmergeMe.hpp"

int PmergeMe::isStruggler;
int PmergeMe::_struggler;
int PmergeMe::_K;

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


//PRINT METHODS

void PmergeMe::printSortedVec(std::vector<int> & sortedVec)
{
    std::cout << "After:  ";
    for (int i = 0; i < (int)sortedVec.size(); i++)
        std::cout << sortedVec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printSortedDeque(std::deque<int> & sortedDeque)
{
    std::cout << "After:  ";
    for (int i = 0; i < (int)sortedDeque.size(); i++)
        std::cout << sortedDeque[i] << " ";
    std::cout << std::endl;
}





//VECTOR

int PmergeMe::isVecSorted(std::vector<int> & unsorted)
{
    std::vector<int> sortedVec(unsorted);
    std::sort(sortedVec.begin(), sortedVec.end());
    std::vector<int>::iterator unsortedIt = unsorted.begin();
    std::vector<int>::iterator sortedVecIt = sortedVec.begin();
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        if (*sortedVecIt != *unsortedIt)
            return 0;
        sortedVecIt++;
        unsortedIt++;
    }
    // PmergeMe::printSortedVec(unsorted);
    return 1;
}

//PARSE INTO VECTOR PAIRS
void PmergeMe::parseVectorArg(std::vector<std::vector<int> >  & myVec, std::vector<int> & unsorted)
{
    std::vector<int> pairVec;
    PmergeMe::isStruggler = 0;
    PmergeMe::_K = std::max(1, static_cast<int>(myVec.size() / 30));
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        pairVec.push_back(unsorted[i]);
        if (pairVec.size() == 2)
        {
            if (pairVec[0] < pairVec[1])
                std::swap(pairVec[0], pairVec[1]);
            myVec.push_back(pairVec);
            pairVec.clear();
        }
    }
    if (!pairVec.empty())
    {
        PmergeMe::_struggler = pairVec.front();
        PmergeMe::isStruggler = 1;
    }
}

//SORT VECTOR PAIRS
static void mergeVectorPair(std::vector<std::vector<int> > & myVec, int begin, int mid, int end)
{
   std::vector<std::vector<int> > mergedVec;
   mergedVec.reserve(end - begin + 1);
   int left = begin;
   int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (myVec[left] < myVec[right])
            mergedVec.push_back(myVec[left++]);
        else
            mergedVec.push_back(myVec[right++]);
    }
    while (left <= mid)
        mergedVec.push_back(myVec[left++]);
    while (right <= end)
        mergedVec.push_back(myVec[right++]);
    for (int i = 0; i < (int)mergedVec.size(); ++i)
        myVec[begin + i] = mergedVec[i];
}

static void insertionSortVectorPair(std::vector<std::vector<int> > & myVec, int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        std::vector<int> tempVal(myVec[i + 1]);
        int j = i + 1;
        while (j > begin && myVec[j - 1] > tempVal)
        {
            myVec[j] = myVec[j - 1];
            j--;
        }
        myVec[j] = tempVal;
    }
}

void PmergeMe::sortVectorPairs(std::vector<std::vector<int> > & myVec, int begin, int end)
{
    if (end - begin > PmergeMe::_K)
    {
        int mid = begin + (end - begin) / 2;
        sortVectorPairs(myVec, begin, mid);
        sortVectorPairs(myVec, mid+1, end);
        mergeVectorPair(myVec, begin, mid, end);
    }
    else
        insertionSortVectorPair(myVec, begin, end);
}




//CREATE MAIN CHAIN AND PEND FROM VECTOR PAIR
void PmergeMe::createVectorMainChainAndPend(std::vector<std::vector<int> > & myVec, std::vector<int> & mainChain, std::vector<int> & pend)
{
    for (int i = 0; i < (int)myVec.size(); i++)
    {
        if (i == 0)
            mainChain.push_back(myVec[i][1]);
        mainChain.push_back(myVec[i][0]);
        if (i != 0)
            pend.push_back(myVec[i][1]);
    }
}



//BINARY INSERTION SEARCH FOR VECTOR
static int binarySearchVector(std::vector<int> & mainChain, int item, int low, int high)
{
    if (high <= low)
        return item > mainChain[low] ? (low + 1) : low;
    
    int mid  = (low + high) / 2;
    if (item == mainChain[mid])
        return mid + 1;
    if (item > mainChain[mid])
        return binarySearchVector(mainChain, item, mid + 1, high);
    return binarySearchVector(mainChain, item, low, mid - 1);
}

void PmergeMe::insertionSortVector(std::vector<int> & mainChain, std::vector<int> & pend)
{
    for (int i = 0; i < (int)pend.size(); i++)
    {
        int item = pend[i];
        int pos = binarySearchVector(mainChain, item, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, item);
    }
    if (PmergeMe::isStruggler)
    {
        int pos = binarySearchVector(mainChain, PmergeMe::_struggler, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, PmergeMe::_struggler);
    }
}



//DEQUE


int PmergeMe::isDequeSorted(std::deque<int> & unsorted)
{
    std::deque<int> sortedVec(unsorted);
    std::sort(sortedVec.begin(), sortedVec.end());
    std::deque<int>::iterator unsortedIt = unsorted.begin();
    std::deque<int>::iterator sortedVecIt = sortedVec.begin();
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        if (*sortedVecIt != *unsortedIt)
            return 0;
        sortedVecIt++;
        unsortedIt++;
    }
    // PmergeMe::printSortedDeque(unsorted);
    return 1;
}

//PARSE INTO DEQUE PAIRS
void PmergeMe::parseDequeArg(std::deque<std::deque<int> > & myDeque, std::deque<int> & unsorted)
{
    std::deque<int> pairDeque;
    PmergeMe::isStruggler = 0;
    PmergeMe::_K = std::max(1, static_cast<int>(myDeque.size() / 30));
    for (int i = 0; i < (int)unsorted.size(); i++)
    {
        pairDeque.push_back(unsorted[i]);
        if (pairDeque.size() == 2)
        {
            if (pairDeque[0] < pairDeque[1])
                std::swap(pairDeque[0], pairDeque[1]);
            myDeque.push_back(pairDeque);
            pairDeque.clear();
        }
    }
    if (!pairDeque.empty())
    {
        PmergeMe::_struggler = pairDeque.front();
        PmergeMe::isStruggler = 1;
    }
}

//SORT DEQUE PAIRS
static void mergeDequePair(std::deque<std::deque<int> > & myVec, int begin, int mid, int end)
{
   std::deque<std::deque<int> > mergedVec;
   int left = begin;
   int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (myVec[left] < myVec[right])
            mergedVec.push_back(myVec[left++]);
        else
            mergedVec.push_back(myVec[right++]);
    }
    while (left <= mid)
        mergedVec.push_back(myVec[left++]);
    while (right <= end)
        mergedVec.push_back(myVec[right++]);
    for (int i = 0; i < (int)mergedVec.size(); ++i)
        myVec[begin + i] = mergedVec[i];
}

static void insertionSortDequePair(std::deque<std::deque<int> > & myVec, int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        std::deque<int> tempVal(myVec[i + 1]);
        int j = i + 1;
        while (j > begin && myVec[j - 1] > tempVal)
        {
            myVec[j] = myVec[j - 1];
            j--;
        }
        myVec[j] = tempVal;
    }
}

void PmergeMe::sortDequePairs(std::deque<std::deque<int> > & myDeque, int begin, int end)
{
    if (end - begin > _K)
    {
        int mid = begin + (end - begin) / 2;
        sortDequePairs(myDeque, begin, mid);
        sortDequePairs(myDeque, mid+1, end);
        mergeDequePair(myDeque, begin, mid, end);
    }
    else
        insertionSortDequePair(myDeque, begin, end);
}

//CREATE MAIN CHAIN AND PEND FROM DEQUE PAIR 
void PmergeMe::createDequeMainChainAndPend(std::deque<std::deque<int> > & myDeque, std::deque<int> & mainChain, std::deque<int> & pend)
{
    for (int i = 0; i < (int)myDeque.size(); i++)
    {
        mainChain.push_back(myDeque[i][0]);
        pend.push_back(myDeque[i][1]);
    }
    mainChain.push_front(pend.front());
    pend.erase(pend.begin());
}


//BINARY INSERTION SEARCH FOR DEQUE
static int binarySearchDeque(std::deque<int> & mainChain, int item, int low, int high)
{
    if (high <= low)
        return item > mainChain[low] ? (low + 1) : low;
    
    int mid  = (low + high) / 2;
    if (item == mainChain[mid])
        return mid + 1;
    if (item > mainChain[mid])
        return binarySearchDeque(mainChain, item, mid + 1, high);
    return binarySearchDeque(mainChain, item, low, mid - 1);
}


void PmergeMe::insertionSortDeque(std::deque<int> & mainChain, std::deque<int> & pend)
{
    for (int i = 0; i < (int)pend.size(); i++)
    {
        int item = pend[i];
        int pos = binarySearchDeque(mainChain, item, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, item);
    }
    if (PmergeMe::isStruggler)
    {
        int pos = binarySearchDeque(mainChain, PmergeMe::_struggler, 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, PmergeMe::_struggler);
    }
}