#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <exception>
class BaseException :  std::exception
{
public:
    virtual const char* print_description()
    {
        return "Unknown error occurred.";
    }
};

#endif // BASE_ERROR_H
