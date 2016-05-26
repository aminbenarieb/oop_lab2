#ifndef ERROR_LIST_H
#define ERROR_LIST_H

#include "base_error.h"

class ExceptionList : BaseException
{
public:
    virtual const char* what()
    {
        return "Unknown error occurred.";
    }
};

class ExceptionMemory : public ExceptionList
{
public:
    virtual const char* what()
    {
        return "Unable to allocate memory.";
    }
};

class ExceptionLink : public ExceptionList
{
public:
    virtual const char* what()
    {
        return "Unable to get data with given link.";
    }
};

class ExceptionPop : public ExceptionList
{

public:
    const char* what()
    {
        return "Unable to pop last element.";
    }

};


#endif // ERROR_LIST_H
