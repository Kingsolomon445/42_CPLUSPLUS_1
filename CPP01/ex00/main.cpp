#include "Zombie.hpp"


int main(void)
{
    Zombie *master = newZombie("Master");
    master->announce();
    randomChump("Slave");
    delete master;
    return (0);
}