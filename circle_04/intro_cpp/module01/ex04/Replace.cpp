#include "Replace.hpp"

void Replace::checkEvents(
        std::string & buffer,
        std::string find,
        std::string put) {

    size_t skip = 0;
    skip = buffer.find(find, skip);
    while (skip != std::string::npos) {
        buffer = buffer.substr(0, skip) + put + buffer.substr(skip + find.length(), buffer.length());
        skip = buffer.find(find, skip+1);
    }
}
