/*  Class:          LinkedList
    Author:         Ryan Wood
    Created On:     February 11, 2018
    Last Modified:  April 14, 2018
    Purpose:        demonstrate use of Linked List structure.
                    In order to utilize this data structure
                    the type of data stored in the LinkedList
                    must have a member named key and a member
                    named nodeLink, which is a pointer to another
                    item of the same datatype
*/
/*Linked List Definition file*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>

template<typename type, std::size_t CAPACITY>
class LinkedList
{
    typedef type* node;//make the pointer easier to deal with
    public:
        /*  Function:   LinkedList()
            Purpose:    default constructor. sets head to null
                        and opens the output file
            Return:     an instance of an empty LinkedList
        */
        LinkedList();

        /*  Function:   ~LinkedList()
            Purpose:    default destructor. Closes the output file
        
        */
        ~LinkedList();

        /*  Function:   size()
            Purpose:    retrieves the number of nodes in the list
            Return:     the number of elements
        */
        std::size_t size() const;

        /*  Function:   insert(type)
            Purpose:    inserts a new node into the list
            Parameters: the data
        */
        void insert(node);

        /*  Function:   remove(node)
            Purpose:    removes the given item from the LinkedList
                        if it is in the list, Linking what was
                        previously linked to it up to whatever it
                        is currently linked to and deleting the
                        item, freeing its allocated memory
            Parameters: the item
        */
        void remove(node);

        /*  Function:   isFull() const
            Purpose:    determines whether the Linked List data
                        sturcture is full, unable to take more values
            Return:     whether the list is full
        */
        bool isFull() const;

        /*  Function:   isEmpty() const
            Purpose:    determines whether the Linked List has
                        no data stored in it
            Return:     whether the list is empty
        */
        bool isEmpty() const;

        /*  Function:   find(string)
            Purpose:    finds an item in the list that has a
                        value for a member named key that matches
                        the given key value
            Paramters:  the key
            Return:     the item or a null element
        */
        node find(std::string key) const;

        /*  Function:   print(ostream&) const
            Purpose:    prints the list using the given ostream handle,
                        printing the items with a newline after each entry
            Paramters:  the output stream
            Return:     the output stream
        */
        std::ostream& print(std::ostream&) const;

        /*  Function:   print(ofstream) const
            Purpose:    prints the list using the given file output stream 
                        handle, printing each element one line at a time
            Parameters: the file output stream
            Return:     the file output stream
        */
        std::ofstream& print(std::ofstream&) const;

        /*  Function:   print() const
            Purpose:    prints the list to the console, one item per line
        */
        void print() const;

    private:
        /*  Function:   clear(node)
            Purpose:    deletes the given node and recursively
                        deletes the items linked to it via nodeLink.
                        head may be passed to the function, deleting
                        all data in the list
            Parameters: the node
        */
        void clear(node);

        node head;//pointer to the first data element
};

#include "LinkedList.template"
#endif
