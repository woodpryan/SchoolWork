/*  Class:      Stack
    Purpose:    this container class stores as many elements as the user
                determines in the parameterized constructore in a Last in First Out
                (FIFO) order scheme. Elements are added to the stack using push,
                retrieved using top and removed using pop.
    Author:     Ryan Wood
    Created On: February 17, 2019
*/

/*Stack definition file*/

#ifndef STACK_H
#define STACK_H

#include "../GeneralList/List.h"
#include <iostream>
#include <string>

namespace rimes
{
    class Stack
    {
        public:
            
            /*  Function:   stack()
                Purpose:    default constructor. Creates an instance of
                            an empty stack having a capacity of 100
                Return:     an instance of a stack
            */
            Stack();

            /*  Function:   Stack(size_t)
                Purpose:    constructor. Creates an instance of an empty Stack
                            having the given capacity
                Parmaeters: the capacity
                Return:     an instance of a Stack
            */
            Stack(size_t);

            /*  Function:   ~Stack()
                Purpose:    destructor. Deletes the private List member variable,
                            freeing the memory allocated for the Stack
            */
            ~Stack();

            /*  Function:   push(et)
                Purpose:    pushes the given element onto the top of the stack. The
                            last value given to this function will be the one retrieved
                            by the top function and deleted by the pop function
                Parameters: the value
            */
            void push(et);

            /*  Function:   pop()
                Purpose:    removes the element of the Stack that is at the top
            */
            void pop();

    
            /*  Function:   top() const
                Purpose:    retrives the element of the stack that is on the top. This
                            is the last element that was placed in the stack using push
                Return:     the top element
            */
            et top() const;

            /*  Function:   print() const
                Purpose:    prints the stack in the order that the elements would be
                            popped off, last in first out
            */
            void print() const;

            /*  Function:   size() const
                Purpose:    determines the number of elements that are currently
                            in use, have a value in the stack
                Return:     the size
            */
            size_t size() const;

            /*  Function:   empty() const
                Purpose:    determines whether the stack has no values in it
                Return:     whether size is zero
            */
            bool empty() const;

            /*  Function:   full() const
                Purpose:    determines whether the list can take no more elements
                Return:     whether size is equal to capacity
            */
            bool full() const;

        private:
            List *stackList;
            int   CAPACITY;
    };//Stack class
};//rimes namespace

#endif
