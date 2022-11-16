#include "sed.hpp"

std::string * read_and_replace(
        std::string file_name,
        std::string find,
        std::string put) {
    
    Replace my_own; 
    std::ifstream read_from;
    std::string *replaced;
    std::string buffer;

    replaced = new std::string;

    read_from.open(file_name);
    if(read_from.is_open()){
        while(std::getline(read_from, buffer)) {
            my_own.checkEvents(buffer, find, put);
            replaced->append(buffer+"\n");
        } 
        read_from.close();
        return replaced;
    }
    else {
        std::cout << "something wrong with file\n";
        return NULL; 
    }
}


int main(int argc, char **argv) {
    std::string *replaced;
    if (argc == 4) {
        std::string file_name = argv[1];
        std::ofstream output(file_name + ".replace");
        replaced = read_and_replace(argv[1], argv[2], argv[3]);
        if (replaced) {
            output << *replaced;
            delete replaced;
        }
        output.close();
    }
    else {
        std::cout << "something wrong with argc\n";
        return -1;
    }
    return 0; 
}
