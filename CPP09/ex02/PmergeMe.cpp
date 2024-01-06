#include "PmergeMe.hpp"

std::vector<int> myVec;
std::deque<int> myDeque;
double dequeMilliSec;
double vecMilliSec;
int K;



// ALGORITHM FOR SORTING NUMBERS IN VECTOR CONTAINER
static void mergeVector(int begin, int mid, int end)
{
    std::vector<int> leftVec(myVec.begin() + begin, myVec.begin() + mid + 1);
    std::vector<int> rightVec(myVec.begin() + mid + 1, myVec.begin() + end + 1);
    std::vector<int>::iterator leftVecIt = leftVec.begin();
    std::vector<int>::iterator rightVecIt = rightVec.begin();
    std::vector<int>::iterator myVecIt = myVec.begin() + begin;
    while (leftVecIt != leftVec.end() && rightVecIt != rightVec.end())
    {
        if (*leftVecIt < *rightVecIt)
        {
            *myVecIt = *leftVecIt;
            leftVecIt++;
        }
        else
        {
            *myVecIt = *rightVecIt;
            rightVecIt++;
        }
        myVecIt++;
    }
    while (leftVecIt != leftVec.end())
    {
        *myVecIt = *leftVecIt;
        leftVecIt++;
        myVecIt++;
    }
    while (rightVecIt != rightVec.end())
    {
        *myVecIt = *rightVecIt;
        rightVecIt++;
        myVecIt++;
    }
}

static int isVectorSorted(int begin, int end)
{
    std::vector<int> tempVec(myVec.begin() + begin, myVec.begin() + end + 1);
    std::vector<int> toCheck(myVec.begin() + begin, myVec.begin() + end + 1);
    std::sort(tempVec.begin(), tempVec.end());
    for (int i = 0; i < (int)tempVec.size(); i++)
    {
        if (tempVec[i] != toCheck[i])
            return 0;
    }
    return 1;
}

static void insertionSortVector(int begin, int end)
{
    for (int i = begin; i < end + 1; i++)
    {
        int tempVal = myVec[i + 1];
        int j = i + 1;
        while (j > begin && myVec[j - 1] > tempVal)
        {
            myVec[j] = myVec[j - 1];
            j--;
        }
        myVec[j] = tempVal;
    }
}

static void sortVector(int begin, int end)
{
    if (end - begin > K)
    {
        int mid = begin + (end - begin) / 2;
        sortVector(begin, mid);
        sortVector(mid+1, end);
        mergeVector(begin, mid, end);
    }
    else
        insertionSortVector(begin, end);
}




// ALGORITHM FOR SORTING NUMBERS IN DEQUE CONTAINER
static int isDequeSorted(int begin, int end)
{
    std::deque<int> tempDeque(myDeque.begin() + begin, myDeque.begin() + end + 1);
    std::deque<int> toCheck(myDeque.begin() + begin, myDeque.begin() + end + 1);
    std::sort(tempDeque.begin(), tempDeque.end());
    for (int i = 0; i < (int)tempDeque.size(); i++)
    {
        if (tempDeque[i] != toCheck[i])
            return 0;
    }
    return 1;
}

static void mergeDeque(int begin, int mid, int end)
{
    std::deque<int> leftDeque(myDeque.begin() + begin, myDeque.begin() + mid + 1);
    std::deque<int> rightDeque(myDeque.begin() + mid + 1, myDeque.begin() + end + 1);
    std::deque<int>::iterator leftDequeIt = leftDeque.begin();
    std::deque<int>::iterator rightDequeIt = rightDeque.begin();
    std::deque<int>::iterator myDequeIt = myDeque.begin() + begin;
    while (leftDequeIt != leftDeque.end() && rightDequeIt != rightDeque.end())
    {
        if (*leftDequeIt < *rightDequeIt)
        {
            *myDequeIt = *leftDequeIt;
            leftDequeIt++;
        }
        else
        {
            *myDequeIt = *rightDequeIt;
            rightDequeIt++;
        }
        myDequeIt++;
    }
    while (leftDequeIt != leftDeque.end())
    {
        *myDequeIt = *leftDequeIt;
        leftDequeIt++;
        myDequeIt++;
    }
    while (rightDequeIt != rightDeque.end())
    {
        *myDequeIt = *rightDequeIt;
        rightDequeIt++;
        myDequeIt++;
    }
}


static void insertionSortDeque(int begin, int end)
{
    for (int i = begin; i < end + 1; i++)
    {
        int tempVal = myDeque[i + 1];
        int j = i + 1;
        while (j > begin && myDeque[j - 1] > tempVal)
        {
            myDeque[j] = myDeque[j - 1];
            j--;
        }
        myDeque[j] = tempVal;
    }
}


static void sortDeque(int begin, int end)
{
    if (end - begin > K)
    {
        int mid = begin + (end - begin) / 2;
        sortDeque(begin, mid);
        sortDeque(mid+1, end);
        mergeDeque(begin, mid, end);
    }
    else
        insertionSortDeque(begin, end);
}





//PRINTING UTILS
void printUnsorted()
{
    std::cout << "Before:    ";
    std::cout << "Unsorted Vector:   ";
    for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Before:    ";
    std::cout << "Unsorted deque:   ";
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

}

void printSorted()
{
    std::cout << "After:     ";
    std::cout << "Sorted Vector:   ";
    for (std::vector<int>::iterator i = myVec.begin(); i != myVec.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    std::cout << "After:     ";
    std::cout << "Sorted deque:   ";
    for (std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printTimeTaken()
{
    if (isVectorSorted(0, myVec.size() - 1))
        std::cout << "Time to process a range of " << myVec.size() << " elements with std::vector : " << vecMilliSec << " milliseconds" << std::endl;
    if (isDequeSorted(0, myDeque.size() - 1))
        std::cout << "Time to process a range of " << myDeque.size() << " elements with std::deque : " << dequeMilliSec << " milliseconds" << std::endl;
}



// STARTER FUNCTIONS
void parseArg(char *argv[])
{
    int i = 1;
    while(argv[i])
    {
        int no;
        std::stringstream ss(argv[i]);
        ss >> no;
        myVec.push_back(no);
        myDeque.push_back(no);
        i++;
    }
    K = std::max(1, static_cast<int>(myVec.size() / 30));
}

void checkArg(char *argv[])
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

void sortArg(std::string container_type)
{
    clock_t startTime;
    clock_t endTime;
    startTime = clock();
    if (container_type == "vector" && !isVectorSorted(0, myVec.size() - 1))
        sortVector(0, myVec.size() - 1);
    else
        sortDeque(0, myDeque.size() - 1);
    endTime = clock();
    if (container_type == "vector")
        vecMilliSec = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
    else
        dequeMilliSec = (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;
}