#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <exception>
class BaseException :  std::exception
{
public:
    virtual const char* what()
    {
        return "Unknown error occurred.";
    }
};

#endif // BASE_ERROR_H
