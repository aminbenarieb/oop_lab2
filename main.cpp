#include <iostream>

#include "list.h"
#include "iterator.h"
#include "error_list.h"
#include "error_iterator.h"

using namespace std;

int main()
{
    try
    {
        List<int> list(3, 1, 2, 3);
    }
    catch(ErrorList &error)
    {
        cout << error.print_description()<<endl;
    }
    catch(ErrorIterator &error)
    {
        cout << error.print_description()<<endl;
    }

    return 0;
}
