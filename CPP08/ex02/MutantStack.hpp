#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack<T, Container> & other);

        MutantStack<T, Container> & operator=(const MutantStack<T, Container> & other);

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

} ;

#include "MutantStack.tpp"

#endif