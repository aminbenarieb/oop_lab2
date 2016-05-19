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

        list.push_back(4);
        cout << list << endl;

        list.push_front(0);
        cout << list << endl;

        Iterator <int> iterator(list);
        for (int i = -4; i < 0; i++)
        {
            iterator.push(i, true);
        }
        cout << list << endl;

        list = List<int>(4, 2, 0, 1, 6);
        cout << list << endl;

    }
    catch(ExceptionList &error)
    {
        cout << error.print_description()<<endl;
    }
    catch(ExceptionIterator &error)
    {
        cout << error.print_description()<<endl;
    }

    return 0;
}
