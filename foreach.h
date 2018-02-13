#ifndef FOREACH_H
#define FOREACH_H

#include <functional>

template<typename T, class c>
void foreach(c cont, std::function<void(T, int)> callback)
{
    for(unsigned int i = 0; i < cont.size(); i++) {
        callback(cont[i], i);
    }
}

#endif // FOREACH_H
