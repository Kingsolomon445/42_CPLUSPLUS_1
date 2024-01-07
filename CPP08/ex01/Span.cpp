#include "Span.hpp"

Span::Span(unsigned int N): _vec(new std::vector<int>()), _N(N){}

Span::Span(const Span & other)
{
    *this = other;
}

Span::~Span() {}

Span & Span::operator=(const Span & other)
{
    if (this != &other)
    {
        _N = other._N;
        _vec = new std::vector<int>();
    }
    return *this;
}

const char* Span::SpanLimitReached::what() const throw()
{
    return "Limit Reached!";
}


//MEMBER FNCTIONS
void Span::printNumbers()
{
    for (std::vector<int>::iterator it = _vec->begin(); it != _vec->end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void Span::addNumber(int nb)
{
    if (_vec->size() >= _N)
        throw Span::SpanLimitReached();
    _vec->push_back(nb);
}

void Span::addRangeOfNumbers(int amount, int min_range, int max_range)
{
    if (amount + _vec->size() > _N)
        throw SpanLimitReached();
    srand(time(NULL));
    for (int i = 0; i < amount; i++)
    {
        int random = min_range + (rand() % max_range);
        while (find(_vec->begin(), _vec->end(), random) != _vec->end())
            random = min_range + (rand() % max_range);
        _vec->push_back(random);
    }
}

int Span::shortestSpan()
{
    std::vector<int> vecCopy(*_vec);
    std::sort(vecCopy.begin(), vecCopy.end());
    int shortestSp = INT_MAX;
    for (int i = 0; i < (int)vecCopy.size() - 1; i++)
    {
        if (vecCopy[i + 1] - vecCopy[i] < shortestSp)
            shortestSp = vecCopy[i + 1] - vecCopy[i];
    }
    return shortestSp;
}

int Span::longestSpan()
{
    
    int min = *(std::min_element(_vec->begin(), _vec->end()));
    int max = *(std::max_element(_vec->begin(), _vec->end()));
    return max - min;
}