#include "Zombie.hpp"

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::get_name(std::string name) {
    this->name = name;
}


Zombie::~Zombie() {
    std::cout << name << ": finally killed" << std::endl;
}
