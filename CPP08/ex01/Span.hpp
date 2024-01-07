#ifndef SPAN_H
#define SPAN_H

#include <exception>
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

class Span
{
    private:
        std::vector<int> *_vec;
        unsigned int _N;

    public:
        Span(unsigned int N);
        Span(const Span & other);
        ~Span();

        Span & operator=(const Span & other);

        void addNumber(int nb);
        void addRangeOfNumbers(int amount, int min_range, int max_range);
        void printNumbers();
        int shortestSpan();
        int longestSpan();

        class SpanLimitReached: public std::exception
        {
            public:
                virtual const char* what() const throw();
        }   ;
} ;

#endif