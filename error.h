#ifndef ERROR_H
#define ERROR_H

#include <exception>

class Error : public std::exception
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};



#endif // ERROR_H
