/*  Class:      Queue
    Purpsoe:    this container class takes elements using the push function
                into a List that may be of any size the use wishes. The
                elements are treated with a first in first out (FIFO)
                order scheme. The pop function may be used to remove elements
                and the top function may be used to get the element on
                the top of the queue.
    Author:     Ryan Wood
    Created On: February 17, 2018
*/

/*Queue implementation file*/

#include "Queue.h"
#include "../GeneralList/List.h"

#include <iostream>
#include <string>

using namespace std;
using namespace rimes;

Queue::Queue()
{
    CAPACITY = 100;
    qList       = new List(CAPACITY);
}

Queue::Queue(size_t cap)
{
    CAPACITY = cap;
    qList    = new List(CAPACITY);
}

Queue::~Queue()
{
    delete(qList);
}

void Queue::push(et val)
{
    if(!qList->full())
    {
        qList->insertBefore(val);
    }
}

void Queue::pop()
{
    if(!qList->empty())
    {
        qList->last();
        qList->erase();
        qList->first();
    }
}

void Queue::print() const
{
    string strVal;
    int    count = 0;
    int    vals  = 0;

    for(count = qList->size()-1; count >= 0; count--)
    {
        strVal = qList->getElement(count);
        cout << strVal << " ";
        vals++;
        if(vals%10 == 0)
            cout << endl;
    }
}
            
et Queue::top() const
{
    et val = "";

    if(!qList->empty())
    {
        val = qList->getElement(qList->size()-1);
    }
    return val;
}

size_t Queue::size() const
{
    return qList->size();
}

bool Queue::empty() const
{
    return qList->empty();
}

bool Queue::full() const
{
    return qList->full();
}

