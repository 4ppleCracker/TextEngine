#ifndef JOIN_H_INCLUDED
#define JOIN_H_INCLUDED

#include "foreach.h"

std::string join(std::vector<std::string> tojoin, std::string del=" ")
{
    std::string ret = "";
    foreach<std::string>(tojoin, [&ret, del](std::string val, int i){
        ret.append(val);
        ret.append(del);
    });
    return ret;
}

#endif // JOIN_H_INCLUDED
