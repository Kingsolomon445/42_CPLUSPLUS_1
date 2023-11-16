#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(const Brain & other)
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called!" << std::endl;
}

void Brain::setIdea(std::string idea, int i)
{
    ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
    return ideas[i];
}