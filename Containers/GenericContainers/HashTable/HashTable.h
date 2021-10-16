/*  Class:      HashTable
    Author:     Ryan Wood
    Purpose:    demonstrate an understanding of hash tables and how
                they work to make data storage faster and simpler.
                In order to use this Hash Table, the datatype must
                include a string member named key and a member named nodeLink,
                which is a pointer to another item of the same data type
    Created On: April 14, 2018
*/
/*Hash Table definition*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../List/List.h"
#include "../LinkedList/LinkedList.h"

template<typename type, size_t CAPACITY>
class HashTable
{
    typedef type* element;
    public:
        HashTable();

        /*  Function:   insert(element)
            Purpose:    inserts the given element into the table
            Parameters: an item that includes a public member named key
        */
        void insert(element);

        /*  Function:   remove(element)
            Purpose:    removes an element from the table that has the
                        given key.
            Parameters: a key that may be in the table
        */
        void remove(string key);

        /*  Function:   getElement(string) const
            Purpose:    retrieves the element from the list having the
                        given key
            Parameters: the key
            Return:     an element from the table or a NULL element
        */
        type* getElement(string key) const;

        /*  Function:   isPresent(string) const
            Purpose:    determines whether there is an element in
                        the table having the given key
            Parameters: a key that may be in the list
            Return:     whether the key was found
        */
        bool isPresent(string key) const;
        
        /*  Function:   size() const
            Purpose:    determines the number of elements in the list
                        by going through each element of the list and
                        retrieving the size of the element's Linked List
                        and adding those totals together
            Return:     the number of items in the list
        */
        size_t size() const;

        /*  Function:   print(ostream&) const
            Purpose:    This function prints the table using the given
                        output stream, printing each element on its own
                        line and printing "Data Hole" for those parts of
                        the table that have no items stored
            Parameters: the output stream
            Return:     the output stream
        */
        std::ostream &print(ostream&) const;

        /*  Function:   print(ofstream& const
            Purpose:    prints the list to the given file output
                        stream, printing each element on its own line
                        and printing "Data hole" for those parts of the
                        table that have no items stored
            Parameters: the file stream
            Return:     the file stream
        */
        std::ofstream &print(ofstream&) const;

        /*  Function:   print() const
            Purpose:    prints the list to the console,
                        printing each element on its own line
                        and printing "data hole" for those parts
                        of the list that have nothing stored
        */
        void print() const;

        /*  Function:   getNumCollisions() const
            Purpose:    retrieves the number of LinkedList elements in
                        the table that have more than one element stored
                        in them and determines how many elements are stored
                        in them, accumulating a total number of element that
                        ended up with the same hash index
            Return:     the number of elements that ended up with the same hash
        */
        int getNumCollisions() const;

        /*  Function:   getNumDataHoles() const
            Purpose:    determines the number of LinkedList elements in the
                        table have no items stored
            Return:     the number of holes in the table
        */
        int getNumDataHoles() const;

    private:
        /*  Function:   hash(string) const
            Purpose:    creates an index from the data in the given
                        key, that is likely to be unique, but will
                        generate some keys that are non-unique
            Parameters: the key
            Return:     the index to the table
        */
        int hash(std::string) const;

        static const int numListVals = 10;

        List<LinkedList<type, numListVals>*, CAPACITY> *list;//these lists are the table
        int                                    numElements;//number of data values
};

#include "HashTable.template"
#endif
