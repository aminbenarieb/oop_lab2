#ifndef BASE_LIST_H
#define BASE_LIST_H

#include "node.h"

class BaseList
{
public:
    virtual size_t size() const = 0;

protected:
    size_t length;
};

#endif // BASE_LIST_H
