#ifndef STRINGSPLIT_H_INCLUDED
#define STRINGSPLIT_H_INCLUDED

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}


#endif // STRINGSPLIT_H_INCLUDED
