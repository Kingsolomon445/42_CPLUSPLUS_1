#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain
{
    protected:
        std::string *ideas;

    public:
        Brain();
        Brain(const Brain & other);
        ~Brain();

        Brain & operator=(const Brain &other);

        std::string getIdea(int i);
        void setIdea(std::string idea, int i);
} ;

#endif