#include "external.hpp"

void randomChump(std::string name) {
    Zombie some_zombie(name);
    some_zombie.announce();
    std::cout << "\ndesctraction...\n";
}
