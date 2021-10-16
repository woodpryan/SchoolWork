#include "List.h"
#include <string>
#include <iostream>

using namespace std;
using namespace rimes;

int main()
{
    List myList(6);

    myList.insertAfter("Ryan");
    cout << myList << endl;

    cout << endl;

    myList.insertAfter("Heather");
    cout << myList << endl;

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
    return 0;
}
