#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

class PmergeMe
{
    private:
        static int isStruggler;
        static int _struggler;
        static int _K;
        PmergeMe();
        PmergeMe(const PmergeMe & other);
        ~PmergeMe();

        PmergeMe & operator=(const PmergeMe & other);
    
    public:
        static int isVecSorted(std::vector<int> & unsorted);
        static int isDequeSorted(std::deque<int> & unsorted);
        static void printSortedVec(std::vector<int> & sortedVec);
        static void printSortedDeque(std::deque<int> & sortedDeque);
        static void parseVectorArg(std::vector<std::vector<int> > & myVec, std::vector<int> & unsorted);
        static void parseDequeArg(std::deque<std::deque<int> > & myDeque, std::deque<int> & unsorted);
        static void sortVectorPairs(std::vector<std::vector<int> > & myVec, int begin, int end);
        static void sortDequePairs(std::deque<std::deque<int> > & myDeque, int begin, int end);
        static void createVectorMainChainAndPend(std::vector<std::vector<int> > & myVec, std::vector<int> & mainChain, std::vector<int> & pend);
        static void createDequeMainChainAndPend(std::deque<std::deque<int> > & myDeque, std::deque<int> & mainChain, std::deque<int> & pend);
        static void insertionSortVector(std::vector<int> & mainChain, std::vector<int> & pend);
        static void insertionSortDeque(std::deque<int> & mainChain, std::deque<int> & pend);

} ;


#endif