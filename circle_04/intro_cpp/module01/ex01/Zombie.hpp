#include <iostream>

class Zombie{
private:
    std::string name;

public:
    void get_name(std::string name);
    Zombie* newZombie(std::string name);
    void announce(void);
    ~Zombie();
};
