//
// File:    stl_const_iterator.cpp
// Author:  adam.lewis@athens.edu
// Purpose:
// Example of using an iterator with a vector
#include <list>
#include <iostream>
using namespace std;
int main()
{
 list<char> coll;      // list container for character elements
 // append elements from 'a' to 'z'
 for (char c='a'; c<='z'; ++c) {
   coll.push_back(c);
 }
 // print all elements:
 // - iterate over all elements
 list<char>::const_iterator pos;
 for (pos = coll.begin(); pos != coll.end(); ++pos){
     cout << *pos << ' ';
 }
 cout << endl;
}
