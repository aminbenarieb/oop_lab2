#include <iostream>

#include "list.h"
#include "iterator.h"
#include "error.h"

using namespace std;

int main()
{
    try
    {
    }
    catch(Error &error)
    {
        cout<<error.print_description()<<endl;
    }

    return 0;
}
