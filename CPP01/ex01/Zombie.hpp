#ifndef ZOMBIE_H
 #define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();

        void announce(void);
        void setName(std::string name);
        static Zombie* zombieHorde(int N, std::string name);
};
#endif