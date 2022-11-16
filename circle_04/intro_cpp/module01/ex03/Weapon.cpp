#include "Weapon.hpp"

Weapon::Weapon(std::string type){
    this->type = type;
}

const std::string & Weapon::getType(void) {
   const std::string &ref_type = type; 
   return ref_type;
} 

void Weapon::setType(std::string type) {
    this->type = type;
}
