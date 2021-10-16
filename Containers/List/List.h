/*  Assignment:     General List Program
    Author:         Ryan Wood
    Created On:     1/28/2018
    Requirements:   Defined in Document "General List Program"
                    provided by Dr. Rimes
*/
/*List definition file*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>

namespace rimes
{
    typedef int et;
    static const size_t CAPACITY = 20;

    class List
    {
        public:

            /*  Function:   List()
                Purpose:    default constructor
                Return:     an empty List
            */
            List();

            /*  Function:   List()
                Purpose:    copy constructor
                Paramters:  the List to copy
                Return:     a new List with the same values as
                            the one given
            */
            List(const List &lstA);

            /*  Function:   emtpy()
                Purpose:    determines whether the list has no values
                Return:     whether elements are used
            */
            bool empty() const;

            /*  Function:   first()
                Purpose:    sets the position to the first element of the array, 0
            */
            void first();

            /*  Function:   last()
                Purpose:    sets the position of the array to last element
                            in the array, used-1
            */
            void last();

            /*  Function:   prev()
                Purpose:    sets the position back by one index
            */
            void prev();

            /*  Function:   next()
                Purpose:    sets the postition forward by one index
            */
            void next();

            /*  Function:   getPosition() const
                Purpose:    retrieves the current position index
                Return:     the index
            */
            et getPos() const;

            /*  Funcrtion:  setPos(et)
                Purpose:    sets the current position to the given
                            index if it is valid
                Parameters: an index less than the size of the List
            */
            void setPos(et);

            /*  Function:   insertBefore(et)
                Purpose:    inserts the given value before the current
                            position in the list
                Parameters: the value
            */
            void insertBefore(et);

            /*  Function:   insertAfter(et)
                Purpose:    inserts the given value after the
                            current position in the List
                Parameters: the value
            */
            void insertAfter(et);

            /*  Function:   getElement() const
                Purpose:    retrieves the value at the current position
                            in the list
                Return:     the value at the current index
            */
            et getElement() const;

            /*  Function:   getElement(et)
                Purpose:    retrieves the value at the given index to the List
                            if it is valid for the list
                Parameters: the index
                Return:     the value
            */
            et getElement(et pos) const;

            /*  Function:   size()
                Purpose:    gets the size of the list, the number of
                            elements that have been used
                Return:     the number of elements used
            */
            size_t size() const;

            /*  Function:   replace(et)
                Purpose:    replaces the value at the current index
                            to the list with the value given
                Parameters: the value
            */
            void replace(et);

            /*  Function:   erase()
                Purpose:    erases the element at the current index to
                            the list, shifting all other elements down
                            to take the empty place
            */
            void erase();

            /*  Function:   clear()
                Purpose:    deletes all elements in the list, setting
                            pos and used both to 0
            */
            void clear();

        private:
            /*  Function:   copy(List&)
                Purpose:    copies the given list to the current list,
                            element by element, copying the values of
                            the array and the value of pos and used
                Parameters: a valid list
            */
            void copy(const List &lstA);

            et *arry;
            et  used;
            et  pos;
    };//List class
};//namespace

/*  Function:   operator<<(ostream&, List&)
    Purpose:    overloads the stream insertion operator using the given
                output to the console
    Parameters: the console output stream, the List to print
    Return:     a reference to the output stream
*/
std::ostream& operator <<(std::ostream &out, const rimes::List &lst);

/*  Function:   operator <<(ofstream&, List&)
    Purpose:    overloads the given file output stream and prints the
                given list to the file
    Parameters: a reference to the file output stream, 
                a reference to the LIst to print
    Return:     a reference to the file output stream
*/
std::ofstream& operator <<(std::ofstream &out, const rimes::List &lst);

/*  Function:   operator==(List&, List&)
    Purpose:    determines whether the given lists are equal
    Parameters: the first list, the second list
    Return:     whether the lists have the same values
*/
bool operator ==(const rimes::List &lstA, const rimes::List &lstB);

/*  Function:   operator !=(List&, List&)
    Purpose:    determines whether the given lists are not equal
    Parameters: the first list, the second list
    Return:     whether the two lists do not have the same values
*/
bool operator !=(const rimes::List &lstA, const rimes::List &lstB);

/*  Function:   operator +(List&, List&)
    Purpose:    adds the values of the second list into the remaining values
                of the first list, creating a new list with the results
    Parameters: the first list, the second List
    Return:     a list with values of both lists
*/
rimes::List operator +(const rimes::List &lstA, const rimes::List &lstB);

#endif
