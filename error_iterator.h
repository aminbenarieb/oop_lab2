#ifndef ERROR_ITERATOR_H
#define ERROR_ITERATOR_H

#include "base_error.h"

class ExceptionIterator : BaseException
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};

class ExceptionRange : public ExceptionIterator
{
public:
    virtual const char* print_description()
    {
        return "Attempt to apply item out of range!";
    }

};

class ExceptionComparison: public ExceptionIterator
{
public:
    virtual const char* print_description()
    {
        return "Unable to compare different copies's types of lists!";
    }
};



#endif // ERROR_ITERATOR_H
