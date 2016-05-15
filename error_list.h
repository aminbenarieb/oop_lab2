#ifndef ERROR_LIST_H
#define ERROR_LIST_H

#include <exception>

class ExceptionList : public std::exception
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};

class ExceptionMemory : public ExceptionList
{
public:
    virtual const char* print_description()
    {
        return "Unable to allocate memory.";
    }
};

class ExceptionLink : public ExceptionList
{
public:
    virtual const char* print_description()
    {
        return "Unable to get data with given link.";
    }
};

class ExceptionPop : public ExceptionList
{

public:
    const char* out()
    {
        return "Unable to pop last element.";
    }

};


#endif // ERROR_LIST_H
