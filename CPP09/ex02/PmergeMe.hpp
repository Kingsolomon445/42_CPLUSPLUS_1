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
        static double dequeMilliSec;
        static double vecMilliSec;
        static int K;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe & other);
        ~PmergeMe();

        PmergeMe & operator=(const PmergeMe & other);

        static void parseArg(std::vector<std::vector<int> > & myVec, std::deque<std::deque<int> > & myDeque, char *argv[]);
        static void sortVectorPairs(std::vector<std::vector<int> > & myVec);
        static void sortDequePairs(std::deque<std::deque<int> > & myDeque);
        static void checkArg(char *argv[]);

} ;


#endif