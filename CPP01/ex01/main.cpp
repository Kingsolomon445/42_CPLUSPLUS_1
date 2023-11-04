#include "Zombie.hpp"


int main(void)
{
    Zombie* zombie;
    int n;

    n = 5;
    zombie = Zombie::zombieHorde(n, "ghost");
    for (int i = 0; i < n; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return (0);
}