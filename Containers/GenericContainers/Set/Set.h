/*  Class:          Set
    Author:         Ryan Wood Purpose:        This class is implemented as a B-Tree
    Assignment:     2-3 Tree
    Requirements:   1. Each node shall have no less then MIN values except
                       the root node, which may have none if it has no children
                    2. Each node shall contain no more than MAX values
                    3. Values of the B-Tree shall be stored in an array,
                       sorted from smallest to largest value
                    4. Each node shall have no more than MAX+1 children
                    5. For any node that is not a leaf, a value at index i
                       is greater than all the values in its child number i
                       and a value at index i is less than all the values
                       stored in its child number i + 1
                    6. Every leaf in the B-Tree shall have the same depth
    Data Rule:      Any class that is to use this container must
                    overload the stream insertion operator for iostream and
                    for fstream as well as the comparison operators
    Created On:     April 8, 2018
*/
/*************Set Header File******************/

#include <iostream>
#include "../List/List.h"
template<typename dataType, size_t MIN>
class Set
{
    public:
        Set();
        Set(const Set& source);//copy constructor
        ~Set();

        void operator =(const Set& source);
        void clear();
        bool insert(const dataType& val);
        size_t erase(const dataType& val);
        size_t count(const dataType& val) const;
        bool empty() const;
    private:
        //private member variables
        static const size_t    MAX = 2 * MIN;
        size_t                 valueCount;
        List<dataType, MAX+1>  data;
        size_t                 numChildren;
        Set                   *children[MAX+2];

        //private member functions
        bool isLeaf();
        bool looseInsert(const dataType& val);
        bool looseErase(const dataType& target);
        void removeBiggest(dataType& removedItem);
        void fixExcess(size_t index);
        void fixShortage(size_t index);
};

#include "Set.template"

