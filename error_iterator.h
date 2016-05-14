#ifndef ERROR_ITERATOR_H
#define ERROR_ITERATOR_H

#include <exception>

class ErrorIterator : public std::exception
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};




#endif // ERROR_ITERATOR_H
