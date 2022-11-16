#include "Weapon.hpp"

#ifndef HUMANA_HPP
#define HUMANA_HPP

class HumanA {
private:
    Weapon &newone; 
    std::string human_name;

public:
    HumanA(std::string name, Weapon &someone);
    void attack(void);
};

#endif
