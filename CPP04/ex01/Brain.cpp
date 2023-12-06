#include "Brain.hpp"

//CONSTRUCTORS AND DESTRUCTOR
Brain::Brain()
{
    std::cout << "Brain default constructor called!" << std::endl;
    ideas = new std::string[100];
}

Brain::Brain(const Brain &other)
{
    ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain()
{
    delete[] ideas;
    std::cout << "ideas destructed!" << std::endl;
    std::cout << "Brain destructor called!" << std::endl;
}

//COPY ASSIGNMENT OPERATOR
Brain & Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        delete[] ideas;
        ideas = new std::string[100];
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

//SETTERS AND GETTERS
void Brain::setIdea(std::string idea, int i)
{
    ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
    return ideas[i];
}