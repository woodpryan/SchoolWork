// File:        maps_strings.cpp
// Author:	Adam.Lewis@athens.edu
// Purpose:
// Demo use of strings as keys in the Map container
//

#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
   map<string, int> Employees;

   // Examples of assigning Map container contents

   // 1) Assignment using array index notation
   Employees["Mike C."] = 5234;
   Employees["Charlie M."] = 3374;

   // 2) Assignment using member function insert() and STL pair
   Employees.insert(std::pair<string,int>("David D.",1923));
 
   // 3) Assignment using member function insert() and "value_type()"
   Employees.insert(map<string,int>::value_type("John A.",7582));

   // 4) Assignment using member function insert() and "make_pair()"
   Employees.insert(std::make_pair("Peter Q.",5328));

   cout << "Map size: " << Employees.size() << endl;

   for( map<string, int>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
}
