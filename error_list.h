#ifndef ERROR_LIST_H
#define ERROR_LIST_H

#include <exception>

class ErrorList : public std::exception
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};

class ErrorMemory : public ErrorList
{
public:
    virtual const char* print_description()
    {
        return "Unable to allocate memory.";
    }
};

class ErrorLink : public ErrorList
{
public:
    virtual const char* print_description()
    {
        return "Unable to get data with given link.";
    }
};

class ErrorPop : public ErrorList
{

public:
    const char* out()
    {
        return "Unable to pop last element.";
    }

};


#endif // ERROR_LIST_H
