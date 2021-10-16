#include <iostream>
#include "List.h"

using namespace std;
using namespace rimes;

int main()
{
    List myList;

    myList.insertAfter(1);
    myList.insertAfter(2);
    myList.insertAfter(3);

    cout << myList.getElement() << endl;
    cout << myList << endl;

    myList.next();
    cout << myList.getElement() << endl;

    myList.prev();
    cout << myList.getElement() << endl;

    myList.insertAfter(69);
    cout << myList << endl;

    myList.prev();
    myList.insertAfter(70);

    cout << myList << endl;
    cout << myList.getElement() << endl << endl;

    myList.insertBefore(32);
    cout << myList << endl;
    
    cout << myList.getElement() << endl << endl;

    myList.replace(55);

    cout << myList << endl;

    myList.erase();
    cout << myList << endl;

    List yourList(myList);

    if(yourList == myList)
        cout << "Your list is just like mine!" << endl;
    else
        cout << "Something is off here." << endl;

    cout << yourList << endl;

    yourList.first();
    yourList.replace(99);

    cout << yourList << endl;

    yourList.last();
    yourList.insertAfter(27);

    cout << yourList << endl;

    cout << "Testing your list is not equal to mine." << endl;
    if(yourList != myList)
        cout << "I guess your list has changed. :(" << endl;
    else
        cout << "Something is off here." << endl;

    return 0;
}
