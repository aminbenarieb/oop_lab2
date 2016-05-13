#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include "node.h"

template <typename type_t>
class BaseIterator
{
public:
    virtual void begin() = 0;
    virtual void end() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;

protected:
    Node <type_t>* currentItem;
};


#endif // BASE_ITERATOR_H
