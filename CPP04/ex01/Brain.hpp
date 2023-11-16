#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
    protected:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain & other);
        ~Brain();

        std::string getIdea(int i);
        void setIdea(std::string idea, int i);
} ;

#endif