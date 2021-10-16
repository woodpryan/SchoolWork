/*  Class:      Stack
    Purpose:    this container class stores as many elements as the user
                determines in the parameterized constructore in a Last in First Out
                (FIFO) order scheme. Elements are added to the stack using push,
                retrieved using top and removed using pop.
    Author:     Ryan Wood
    Created On: February 17, 2019
*/

/*Stack implementation file*/
#include "Stack.h"
#include "../GeneralList/List.h"

#include <iostream>
#include <string>

using namespace std;
using namespace rimes;

Stack::Stack()
{
    CAPACITY  = 100;
    stackList = new List(CAPACITY);
}

Stack::Stack(size_t cap)
{
    CAPACITY  = cap;
    stackList = new List(CAPACITY);
}

Stack::~Stack()
{
    delete(stackList);
}

void Stack::push(et val)
{
    if(!stackList->full())
    {
        stackList->insertAfter(val);
    }
}

void Stack::pop()
{
    if(!stackList->empty())
    {
        stackList->erase();
    }
}

void Stack::print() const
{
    string strVal;
    int    count = 0;

    for(count = 0; count < stackList->size(); count++)
    {
        strVal = stackList->getElement();
        cout << strVal << " ";
        if(count > 0 && count % 10 == 0)
            cout << endl;
    }
}

et Stack::top() const
{
    et val;

    if(!stackList->empty())
    {
        val = stackList->getElement();
    }
    return val;
}

size_t Stack::size() const
{
    return stackList->size();
}

bool Stack::empty() const
{
    return stackList->empty();
}

bool Stack::full() const
{
    return stackList->full();
}

