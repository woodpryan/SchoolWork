/*  Class:          Queue
    Purpsoe:        this container class takes elements using the push function
                    into a List that may be of any size the use wishes. The
                    elements are treated with a first in first out (FIFO)
                    order scheme. The pop function may be used to remove elements
                    and the top function may be used to get the element on
                    the top of the queue.
    Author:         Ryan Wood
    Created On:     February 17, 2018
    Last Modified:  February 24, 2018
*/

/*Queue definition file*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../List/List.h"

#include <string>

template <typename et, size_t CAPACITY>
class Queue
{
    public:
            
        /*  Function:   Queue()
            Purpose:    default constructor. Creates an empty 
                        Queue with a capacity of 100
            Return:     an instance of a Queue
        */
        Queue();

        /*  Function:   Queue()
            Purpose:    Destructor. Deletes the List, releasing the
                        RAM allocated for the Queue
        */
        ~Queue();

        /*  Function:   push(et)
            Purpose:    pushes the given value into the back of the Queue
            Parameters: the value
        */
        void push(et);

        /*  Function:   pop()
            Purpose:    removes the value that is at the top of the Queue
        */
        void pop();

        /*  Function:   top()
            Purpose:    retrieves the value that is at the top of the Que
            Return:     the top value of the Queue
        */
        et top() const;

        /*  Function:   print() const
            Purpose:    prints the values of the Queue in the
                        First in First Out order n which they would
                        be popped off.
        */
        void print() const;

        /*  Function:   size() const
            Purpose:    retrieves the number of elements that have been
                        used in the queue
            Return:     the size of the Queue
        */
        size_t size() const;

        /*  Function:   empty() const
            Purpose:    determines whether the Queue has no used values
            Return:     whether size is zero
        */
        bool empty() const;

        /*  Function:   full() const
            Purpose:    determines whether the Queue can hold no more values
            Return:     whether size is equal to capacity
        */
        bool full() const;

    private:
        List<et, CAPACITY> *qList;
};//Queue class

template <typename et, size_t CAPACITY>
inline Queue<et, CAPACITY>::Queue()
{
    qList = new List<et, CAPACITY>;
}

template <typename et, size_t CAPACITY>
inline Queue<et, CAPACITY>::~Queue()
{
    delete(qList);
}

template <typename et, size_t CAPACITY>
inline void Queue<et, CAPACITY>::push(et val)
{
    if(!qList->full())
    {
        qList->insertBefore(val);
    }
}

template <typename et, size_t CAPACITY>
inline void Queue<et, CAPACITY>::pop()
{
    if(!qList->empty())
    {
        qList->last();
        qList->erase();
        qList->first();
    }
}

template <typename et, size_t CAPACITY>
inline void Queue<et, CAPACITY>::print() const
{
    int count = 0;
    int vals  = 0;

    for(count = qList->size()-1; count >= 0; count--)
    {
        std::cout << qList->getElement(count) << " ";

        vals++;
        if(vals%10 == 0)
            std::cout << std::endl;
    }
}
            
template <typename et, size_t CAPACITY>
inline et Queue<et, CAPACITY>::top() const
{
    et val;

    if(!qList->empty())
    {
        val = qList->getElement(qList->size()-1);
    }
    return val;
}

template <typename et, size_t CAPACITY>
inline size_t Queue<et, CAPACITY>::size() const
{
    return qList->size();
}

template <typename et, size_t CAPACITY>
inline bool Queue<et, CAPACITY>::empty() const
{
    return qList->empty();
}

template <typename et, size_t CAPACITY>
inline bool Queue<et, CAPACITY>::full() const
{
    return qList->full();
}

#endif
