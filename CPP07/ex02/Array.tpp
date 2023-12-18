#include "Array.hpp"

template <typename T>
Array<T>::Array():_arr(new T[1]), _size(0) {}


template <typename T>
Array<T>::Array(unsigned int n): _arr(new T[n]), _size(n) {}


template <typename T>
Array<T>::Array(const Array & other): _arr(new T[other._size]), _size(other._size)
{
    for (int i = 0; i < other._size; i++)
    {
        _arr[i] = other._arr[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete []_arr;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array & other)
{
    if (this != &other)
    {
        _size = other._size;
        delete []_arr;
        _arr = new T[other._size];
        for (int i = 0; i < other._size; i++)
        {
            _arr[i] = other._arr[i];
        }
    }
    return *this;
}

template <typename T>
T & Array<T>::operator[](int i)
{
    if (i < 0)
        throw std::out_of_range("invalid index!");
    if (i >= _size)
        throw std::out_of_range("index is bigger than size of array!");
    return _arr[i];
}

template <typename T>
int Array<T>::size() const
{
    return _size;
}
