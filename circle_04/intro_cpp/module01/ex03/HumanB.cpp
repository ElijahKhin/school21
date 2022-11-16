#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    human_name = name;
}

void HumanB::setWeapon(Weapon &someone) { 
    newone = &someone;
}


void HumanB::attack(void) {
    std::cout << human_name << " attacks with their ";
    std::cout << newone->getType() << std::endl;
}
