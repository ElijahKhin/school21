#include "external.hpp"

int main(void) {
    Zombie *heap_one;
    Zombie *heap_two;
    Zombie *heap_three;

    heap_one = newZombie("on_heap#1");
    heap_two = newZombie("on_heap#2");
    heap_three = newZombie("on_heap#3");

    std::cout << "________________HEAP_______________\n";
    std::cout << "announcment...\n";
    heap_one->announce();
    heap_two->announce();
    heap_three->announce();
    
    std::cout << "\ndesctraction...\n";

    delete heap_one;
    delete heap_two;
    delete heap_three;

    std::cout << "\n________________STACK_______________\n";
    std::cout << "announcment...\n";
    randomChump("on_stack");
    return 0;
}
