/*  Assignment:     Heap Program
    Author:         Ryan Wood
    Created On:     April 1, 2018
    Requirements:   Create a priority heap class and
                    test it using the program specified
                    in the document Heap Program handed out
                    in class March 27, 2018
*/
/****** Heap Header file *******/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "../List/List.h"

template <typename et, size_t CAPACITY>
class Heap
{
    public:
        /*  Function:   Heap();
            Purpose:    cunstructor. Creates a List with the
                        capacity of the Heap
        */
        Heap();

        /*  Function:   ~Heap();
            Purpose:    destroys the heap, deleting the list pointer
        */
        ~Heap();

        /*  Function:   push(et)
            Purpose:    pushes the given value into the heap, making it the
                        root if it is greater than the rest of the elements
                        in the heap. Shifts elements depending on the new value
            Parameters: the value
        */
        void push(et val);

        /*  Function:   pop()
            Purpose:    deletes the largest element in the heap, the root,
                        moving the element at the end of the list to the
                        top and then walking that value down until a new
                        root is placed and the element is back at a reasonable
                        position in the heap
        */
        void pop();

        /*  Function:   top()
            Purpose:    retrieves the item from the top of the heap, which
                        is the largest item in the heap
            Return:     the largest item in the heap
        */
        et top();

        /*  Function:   size() const
            Purpose:    retrieves the size of the heap, ie the number
                        of elements of the heap that are in use
            Return:     the number of used elements in the heap
        */
        size_t size() const;

        /*  Function:   capacity() const
            Purpose:    retrieves the number of elements that the heap may hold
                        before it is full
            Return:     the capacity of the heap
        */
        size_t capacity() const;

        /*  Function:   full() const
            Purpose:    determines whether the heap is unable to take on any
                        new elements due to size reaching capacity
            Return:     whether the heap is full
        */
        bool full() const;

        /*  Function:   print() const
            Purpose:    prints the heap's elements. Actually, prints out
                        the List, which includes the heap's unused element 0.
        */
        void print() const;

    private:
        List<et, CAPACITY> *list;
};


template<typename et, size_t CAPACITY>
inline Heap<et, CAPACITY>::~Heap()
{
    delete list;
}

template<typename et, size_t CAPACITY>
inline Heap<et, CAPACITY>::Heap()
{
    et nothing;

    list = new List<et, CAPACITY>;
    list->insertAfter(nothing);//fill array position. We won't need it
}

template<typename et, size_t CAPACITY>
inline void Heap<et, CAPACITY>::pop()
{
    bool  isHeap     = true;
    int   curIndex   = 0;
    int   lIndex     = 0;
    int   childIndex = 0;
    int   rIndex     = 0;
    et    lastVal;
    
    if(list->size() <= 1)
        return;
    //get the last value
    lastVal = list->getElement();
    list->erase();

    if(list->getPos() == 0)
        return;

    //move the current index to the first value, the big one
    list->setPos(1);

    //replace the value
    list->replace(lastVal);

    curIndex = list->getPos();
    
    do
    {
        isHeap     = true;
        lIndex     = curIndex * 2;
        rIndex     = (curIndex *2) + 1;
        childIndex = list->max(lIndex, rIndex);

        if(list->max(curIndex, childIndex) == childIndex)
        {
            list->swap(curIndex, childIndex);
            curIndex = childIndex;
            isHeap   = false;
         }
    }while(!isHeap);

    list->last();
}

template<typename et, size_t CAPACITY>
inline void Heap<et, CAPACITY>::push(et val)
{
    bool isHeap      = true;
    int  parentIndex = 0;
    int  childIndex  = 0;
    et   parent;
    et   child;

    list->insertAfter(val);
    childIndex = list->getPos();
    do
    {
        isHeap   = true;

        if(childIndex > 1)
        {
            parentIndex = childIndex/2;
            parent      = list->getElement(parentIndex);
            if(list->max(parentIndex, childIndex) == childIndex)
            {
                list->swap(childIndex, parentIndex);
                childIndex = parentIndex;
                isHeap     = false;
            }
        }
    }while(!isHeap);

    list->last();
}

template<typename et, size_t CAPACITY>
inline et Heap<et, CAPACITY>::top()
{
    if(list->size() > 1)
        return list->getElement(1);
    else
        return list->getElement(0);
}

template<typename et, size_t CAPACITY>
inline size_t Heap<et, CAPACITY>::size() const
{
    return list->size()-1;
}

template<typename et, size_t CAPACITY>
inline size_t Heap<et, CAPACITY>::capacity() const
{
    return CAPACITY;
}

template<typename et, size_t CAPACITY>
inline bool Heap<et, CAPACITY>::full() const
{
    return size() < capacity();
}

template <typename et, size_t CAPACITY>
inline void Heap<et, CAPACITY>::print() const
{
    std::cout << *list << std::endl;
}

#endif
