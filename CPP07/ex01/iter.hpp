#ifndef ITER_H
#define ITER_H

template <typename T, typename  F>void iter(T addr, T len, F func);

template <typename T, typename  F>
void iter(T addr, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(addr[i]);
    }
}
#endif