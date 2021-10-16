#include "List.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    List<string, 3> myList;
    List<int, 3> iList;
    myList.insertAfter("A");
    cout << myList << endl;
    cout << endl;

    myList.insertAfter("B");
    cout << myList << endl;

    cout << "max(0, 1) = " << myList.max(0, 1) << endl;

    myList.swap(0, 1);
    cout << "max(0, 1) = " << myList.max(0, 1) << endl;

    myList.insertAfter("Clayton");
    myList.insertAfter("Sam");

    cout << myList << endl;
    cout << endl;

    myList.replace("John");
    cout << myList << endl;

    myList.insertAfter("Jim");
    if(myList.full())
        cout << "Full" << endl;

    myList.insertAfter("OhNo");
    if(myList.full())
        cout << "Full" << endl;

    myList.insertAfter("OutOfLine");
    if(myList.full())
        cout << "Full" << endl;

    cout << myList << endl;

    iList.insertAfter(1);
    iList.insertAfter(5);
    cout << iList.max(0, 1) << endl;
    iList.insertAfter(8);
    cout << iList << endl;

    return 0;
}
