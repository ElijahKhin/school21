#include <fstream>
#include <iostream>

#ifndef REAPLACE_HPP
# define REAPLACE_HPP

class Replace {
public:
    void checkEvents(
            std::string & buffer,
            std::string find,
            std::string put);
};

#endif
