#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &someone) : newone(someone) {
    human_name = name;
}

void HumanA::attack(void) {
    std::cout << human_name << " attacks with their " << newone.getType() << std::endl;
}
