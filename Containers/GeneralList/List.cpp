/*  Assignment:     General List Program
    Author:         Ryan Wood
    Created On:     1/28/2018
    Requirements:   Defined in Document "General List Program"
                    provided by Dr. Rimes
*/
/*List Implementation file*/

#include <iostream>
#include "List.h"

using namespace std;
using namespace rimes;

List::List()
{
    CAPACITY = 20;
    used     = 0;
    pos      = 0;
    arry     = new et[CAPACITY];
}

List::List(size_t cap)
{
    CAPACITY = cap;
    used     = 0;
    pos      = 0;
    arry     = new et[CAPACITY];
}

List::List(const List &lstA)
{
    copy(lstA);
}

bool List::empty() const
{
    return(used == 0);
}

bool List::full() const
{
    return(used == CAPACITY);
}

void List::first()
{
    pos = 0;
}

void List::last()
{
    pos = used-1;
}

void List::prev()
{
    if(pos > 0)
        pos--;
}

void List::next()
{
    if(pos < CAPACITY-1 && pos < used-1)
        pos++;
}

int List::getPos() const
{
    return pos;
}

void List::setPos(int val)
{
    if(val < used && val > -1)
        pos = val;
}

void List::insertBefore(et val)
{
    et *current;
    et *tmp;
    et *next;

    //case used = 0
    if(used < CAPACITY)
    {
        if(used == 0)
        {
            arry[pos] = val;
        }
        else
        {
            //set current to position address
            current = &arry[pos];
            //set a temp var to the next to last value
            tmp = &arry[used-1];
            next = tmp+1;

            //loop backward up to our current position
            while(tmp >= current)
            {
                //set the next value to be the value before it
                *next = *tmp;
                tmp--;
                next--;
            }
            //now set the current value to the given value
            *current = val;
        }
        //increment how many values there are
        used++;
    }
}

void List::insertAfter(et val)
{
    et *current;
    et *tmp;

    if(used < CAPACITY)
    {
        //case used = 0;
        if(used == 0)
            arry[pos] = val;
        else
        {
            current = &arry[pos];
            tmp = &arry[used-1];
            
            //from the last item to the current item, loop
            //backward through array, moving elements forward by one
            while(tmp >= current)
            {
                *(tmp+1) = *tmp;
                tmp--;
            }
            current++;
            *current = val;
            pos++;
        }
        used++;
    }
}

et List::getElement(int ePos) const
{
    et val = "";

    if(pos >= 0 && pos < used)
    {
        val = arry[ePos];
    }
    return val;
}

et List::getElement() const
{
    et val = "";

    if(used > 0)
    {
        val = arry[pos];
    }

    return val;
}

size_t List::size() const
{
    return used;
}

void List::replace(et val)
{
    arry[pos] = val;
}

void List::erase()
{
    int count = 0;

    if(used > 0)
    {
        //delete current element
        arry[pos] = "";

        //left justify the rest of the array
        count = pos;
        while(count < used)
        {
            arry[count] = arry[count+1];
            count++;
        }
        used--;
        pos--;
    }
}

void List::clear()
{
    int count = 0;
    
    for(count = 0; count < used; count++)
    {
        arry[count] = "";
    }
    used = 0;
    pos = 1;
}

void List::copy(const List &lstA)
{
    int  count = 0;
    et  *iter  = NULL;

    CAPACITY = lstA.getCapacity();
    arry     = new et[CAPACITY];
    used     = 0;
    pos      = 0;

    if(!lstA.empty())
    {
        iter = arry;
        for(count = 0; count < lstA.size(); count++)
        {
            *iter = lstA.getElement(count);
             iter++;
        }
    }
    pos = lstA.getPos();
    used = lstA.size();
}

size_t List::getCapacity() const
{
    return CAPACITY;
}

std::ostream& operator <<(std::ostream &out, const List &lst)
{
    int count = 0;

    for(count = 0; count < lst.size(); count++)
    {
        if(count == 0)
            out << lst.getElement(count);
        else
            out << ", " << lst.getElement(count);
    }

    return out;
}

std::ofstream& operator <<(std::ofstream &out, const rimes::List &lst)
{
     int count = 0;

    for(count = 0; count < lst.size(); count++)
    {
        if(count == 0)
        {
            out << lst.getElement(count);
        }
        else
            out << ", " << lst.getElement(count);
    }

    return out;   
}

bool operator ==(const List &lstA, const List &lstB)
{
    int count = 0;

    if(lstA.size() != lstB.size())
        return false;

    for(count = 0; count < lstA.size(); count++)
    {
        if(lstA.getElement(count) != lstB.getElement(count))
            return false;
    }

    return true;
}

bool operator !=(const List &lstA, const List &lstB)
{
    return(!(lstA == lstB));
}

List operator +(const List &lstA, const List &lstB)
{
    int  count = 0;
    List lstC;

    for(count = 0; count < lstA.size(); count++)
    {
        lstC.insertAfter(lstA.getElement(count));
    }
    for(count = 0; count < lstB.size(); count++)
    {
        lstC.insertAfter(lstA.getElement(count));
    }

    return lstC;
}


