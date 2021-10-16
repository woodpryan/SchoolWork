/*  Assignment:     General List Program
    Author:         Ryan Wood
    Created On:     1/28/2018
    Last Modified:  4/15/2018
*/
/*List definition file*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <string>

template <typename et, size_t CAPACITY>
class List
{
    public:

        /*  Function:   List()
            Purpose:    default constructor. Creates a List with a capacity of 20
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

        /*  Function:   full()
            Purpose:    determines whether the list is unable
                        to take on any new values
            Return:     whether used is equal to CAPACITY
        */
        bool full() const;

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
        int getPos() const;

        /*  Funcrtion:  setPos(int)
            Purpose:    sets the current position to the given
                        index if it is valid
            Parameters: an index less than the size of the List
        */
        void setPos(int);

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

        /*  Function:   getElement(int)
            Purpose:    retrieves the value at the given index to the List
                        if it is valid for the list
            Parameters: the index
            Return:     the value
        */
        et getElement(int pos) const;

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

        /*  Function:   swap(int, int)
            Purpose:    swaps the element at the given first index
                        with the element at the given second index
                        if neither index is greater than the current
                        number of values used
            Parameters: the first index, the second index
        */
        void swap(int indexA, int indexB);

        /*  Function:   max(int, int)
            Purpose:    determines which of the two given indexes
                        to the list contains the largest value,
                        returning the index with the largest value.
                        If one index has a null value, returns the
                        other. If they are both null returns -1
            Parameters: the first index, the second index
            Return:     the index holding the larger value
        */
        int max(int indexA, int indexB);

        /*  Function:   getCapacity()
            Purpose:    returns the maximum number of elements the
                        list is able to hold
            Return:     capacity
        */
        size_t getCapacity() const;

    private:
        /*  Function:   copy(List&)
            Purpose:    copies the given list to the current list,
                        element by element, copying the values of
                        the array and the value of pos and used
            Parameters: a valid list
        */
        void copy(const List &lstA);

        et     *arry;//the list itself
        int     used;//how many elements have been used
        int     pos;//the current pointer to the list
};//List class

template <typename et, size_t CAPACITY>
inline List<et, CAPACITY>::List()
{
    used     = 0;
    pos      = 0;
    arry     = new et[CAPACITY];
}

template <typename et, size_t CAPACITY>
inline List<et, CAPACITY>::List(const List &lstA)
{
    copy(lstA);
}

/*  Function:   operator<<(ostream&, List&)
    Purpose:    overloads the stream insertion operator using the given
                output to the console
    Parameters: the console output stream, the List to print
    Return:     a reference to the output stream
*/
template <typename et, size_t CAPACITY>
std::ostream& operator <<(std::ostream &out, const List<et, CAPACITY> &lst);

/*  Function:   operator <<(ofstream&, List&)
    Purpose:    overloads the given file output stream and prints the
                given list to the file
    Parameters: a reference to the file output stream, 
                a reference to the LIst to print
    Return:     a reference to the file output stream
*/
template <typename et, size_t CAPACITY>
std::ofstream& operator <<(std::ofstream &out, const List<et, CAPACITY> &lst);

/*  Function:   operator==(List&, List&)
    Purpose:    determines whether the given lists are equal
    Parameters: the first list, the second list
    Return:     whether the lists have the same values
*/
template <typename et, size_t CAPACITY>
bool operator ==(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB);

/*  Function:   operator !=(List&, List&)
    Purpose:    determines whether the given lists are not equal
    Parameters: the first list, the second list
    Return:     whether the two lists do not have the same values
*/
template <typename et, size_t CAPACITY>
bool operator !=(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB);

/*  Function:   operator +(List&, List&)
    Purpose:    adds the values of the second list into the remaining values
                of the first list, creating a new list with the results
    Parameters: the first list, the second List
    Return:     a list with values of both lists
*/
template <typename et, size_t CAPACITY>
List<et, CAPACITY> operator +(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB);

template<typename et, size_t CAPACITY>
inline bool List<et, CAPACITY>::empty() const
{
    return(used == 0);
}

template<typename et, size_t CAPACITY>
inline bool List<et, CAPACITY>::full() const
{
    return(used == CAPACITY);
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::first()
{
    pos = 0;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::last()
{
    pos = used-1;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::prev()
{
    if(pos > 0)
        pos--;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::next()
{
    if(pos < CAPACITY-1 && pos < used-1)
        pos++;
}

template<typename et, size_t CAPACITY>
inline int List<et, CAPACITY>::getPos() const
{
    return pos;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::setPos(int val)
{
    if(val < used && val > -1)
        pos = val;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::insertBefore(et val)
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

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::insertAfter(et val)
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

template<typename et, size_t CAPACITY>
inline et List<et, CAPACITY>::getElement(int ePos) const
{
    et val;

    if(pos >= 0 && pos < used)
    {
        val = arry[ePos];
    }
    return val;
}

template<typename et, size_t CAPACITY>
inline et List<et, CAPACITY>::getElement() const
{
    et val;

    if(used > 0)
    {
        val = arry[pos];
    }

    return val;
}

template<typename et, size_t CAPACITY>
inline size_t List<et, CAPACITY>::size() const
{
    return used;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::replace(et val)
{
    arry[pos] = val;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::erase()
{
    int count = 0;

    if(used > 0)
    {
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

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::swap(int indexA, int indexB)
{
    et tmp;
    if(indexA <= used && indexB <= used)
    {
        tmp          = arry[indexA];
        arry[indexA] = arry[indexB];
        arry[indexB] = tmp;
    }
}

template<typename et, size_t CAPACITY>
inline int List<et, CAPACITY>::max(int indexA, int indexB)
{
    int maxIndex = -1;
    et  valA;
    et  valB;

    if(indexA >= used || indexB >= used)
    {
        if(indexA >= used && indexB >= used)
            maxIndex = -1;
        else if(indexA >= used)
            maxIndex = indexB;
        else
            maxIndex = indexA;
    }
    else
    {
        valA = arry[indexA];
        valB = arry[indexB];

        if(valA > valB)
            maxIndex = indexA;
        else
            maxIndex = indexB;
    }

    return maxIndex;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::clear()
{
    int count = 0;
    et  null;
    
    for(count = 0; count < used; count++)
    {
        arry[count] = null;
    }
    used = 0;
    pos = 1;
}

template<typename et, size_t CAPACITY>
inline void List<et, CAPACITY>::copy(const List &lstA)
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

template<typename et, size_t CAPACITY>
inline size_t List<et, CAPACITY>::getCapacity() const
{
    return CAPACITY;
}

template<typename et, size_t CAPACITY>
inline std::ostream& operator <<(std::ostream &out, const List<et, CAPACITY> &lst)
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

template<typename et, size_t CAPACITY>
inline std::ofstream& operator <<(std::ofstream &out, const List<et, CAPACITY> &lst)
{
    int count = 0;

    for(count = 0; count < lst.size(); count++)
    {
        out << lst.getElement(count) << " ";
    }

    return out;   
}

template<typename et, size_t CAPACITY>
inline bool operator ==(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB)
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

template<typename et, size_t CAPACITY>
inline bool operator !=(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB)
{
    return(!(lstA == lstB));
}

template<typename et, size_t CAPACITY>
inline List<et, CAPACITY> operator +(const List<et, CAPACITY> &lstA, const List<et, CAPACITY> &lstB)
{
    int  count = 0;
    List<et, CAPACITY> lstC;

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
#endif
