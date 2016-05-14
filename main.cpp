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
        cout << list << endl;
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
