#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
    private:
        T *_arr;
        int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T> & other);
        ~Array();

        Array<T> & operator=(const Array<T> & other);
        T & operator[](int i);

        int size() const;
} ;

#include "Array.tpp"

#endif