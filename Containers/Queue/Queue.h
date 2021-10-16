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

/*Queue definition file*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../GeneralList/List.h"

#include <string>

namespace rimes
{
    class Queue
    {
        public:
            
            /*  Function:   Queue()
                Purpose:    default constructor. Creates an empty 
                            Queue with a capacity of 100
                Return:     an instance of a Queue
            */
            Queue();

            /*  Function:   Queue(size_t)
                Purpose:    constructor. Creates an empty Queue with
                            the given size for capacity
                Parameters: the capacity
                Return:     an instance of a Queue
            */
            Queue(size_t);

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
            List   *qList;
            size_t  CAPACITY;
    };//Queu class
};//rimes namespace

#endif
