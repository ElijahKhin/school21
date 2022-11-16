#include "HumanA.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
private:
    std::string human_name;
    Weapon *newone;

public:
    HumanB(std::string name);
    void setWeapon(Weapon &someone);
    void attack(void);

};

#endif
