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



#endif // ERROR_LIST_H
