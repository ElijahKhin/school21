#include "external.hpp"

int main(void) {
    int i;
    int N = 10;
    std::string name = "Jon Snow";
    Zombie *horde;

    horde = zombieHorde(N, name);
    for (i=0; i < N; i++)
        horde[i].announce();
    delete [] horde;
    return 0;
}
