#ifndef BASE_LIST_H
#define BASE_LIST_H

#include "node.h"

class BaseList
{
public:
    virtual size_t size() const = 0;
    virtual void inc_size();
    virtual void dec_size();
    virtual void set_size();
    virtual bool empty();

protected:
    size_t count;
};

#endif // BASE_LIST_H
