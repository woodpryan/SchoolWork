/*  Assignment:     Name Grade Sorted Link List
    Author:         Ryan Wood
    Created On:     February 11, 2018
    Purpose:        demonstrate use of Linked List structure
*/
/*Linked List Definition file*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include "Student.h"

class LinkedList
{
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

    /*  Function:   getNumNodes()
        Purpose:    retrieves the number of nodes in the list
        Return:     the number of elements
    */
    int getNumNodes();

    /*  Function:   insert(string, double)
        Purpose:    inserts a new node having the given name and grade
                    into the list in order of grade, name, AND A student
        Parameters: the name, the grade as a percentage
    */
    void insert(std::string, double);

    /*  Function:   print()
        Purpose:    prints the list in name order
    */
    void print();

    /*  Function:   printReverse()
        Purpose:    prints the list in reverse order by name
    */
    void printReverse();

    /*  Function:   printByGrade()
        Purpose:    prints the list in grade order
    */
    void printByGrade();

    /*  Function:   printAStudents()
        Purpose:    prints the A students that are in the list
                    in order of their grades from greatest to least
    */
    void printAStudents();

private:
    /*  Function:   printReverse(node)
        Purpose:    prints the list in reverse order by name
                    using a recursive function call
        Parameters: the head node
    */
    void printReverse(node);
    node head;//pointer to the first student
};

#endif
