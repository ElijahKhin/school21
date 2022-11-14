#include "external.hpp"

Zombie* zombieHorde(int N, std::string name){
    int i;
    Zombie *horde;
    horde = new Zombie[N];
    if (N > 0) {
        for (i=0; i<N; i++){
            horde[i].get_name(name);
        }
        return horde;
    }
    std::cout << "wrong N. It has to be > 0\n"; 
    return 0;
}
