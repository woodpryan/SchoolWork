/*  Assignment:     Hash Program
    Author:         Ryan Wood
    Created On:     April 14, 2018
    Purpose:        Read a data file filled with students and
                    their phone numbers and store them in a
                    Hash Table. Print the final table and
                    demonstrate looking up keys that are there
                    and keys that are not in the table. Demonstrate
                    the ability to look up a name and get their phone
                    number
*/
/** Hash Table Main file**/

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include "../LinkedList/Student.h"

using namespace std;

ifstream inFile("HashNamesAndPhone.txt");
ofstream outFile("HashOutput.out");

HashTable<Student, 51> table;

/*  Function:   isNumber(char)
    Purpose:    determines whether the given character
                falls within the ascii rang 48 and 57
                which is numbers 0 through 9
    Parameters: the character
    Return:     whether the character is a number
*/
bool isNumber(char c)
{
    return (c > 47 && c < 58);//0 - 9 ASCII
}

/*  Function:   trim(string)
    Purpose:    trims the trailing space, tab, or
                newline characters from the given string
    Parameters: a reference to a string
*/
void trim(string &str)
{
    str.erase(str.find_last_not_of(" \n\r\t")+1);
}

/*  Function:   fillTable()
    Purpose:    reads the data from the file an creates a student for
                each line it finds. Places the student into the table
*/
void fillTable()
{
    Student *student = NULL;
    int      index   = 0;
    string   name;
    string   phone;

    while(getline(inFile, name))
    {
        //test for invalid line
        if(name.length() < 2)
            continue;

        /* get an index to the string at which we should divide
           between the end of the name and the beginning of the phone number*/
        index = 0;
        while(!isNumber(name[index]) && index < name.length())
        {
            index++;
        }

        //split the line into phone and name
        phone = name.substr(index, name.length());
        name  = name.substr(0, index);

        //trim any trailing space/newlines
        trim(name);
        trim(phone);
        
        //create a student. This function sets the key variable too
        student = new Student(name, phone);
        table.insert(student);
    }
}

int main()
{
    if(!inFile)
    {
        cout    << "No data file found!" << endl;
        outFile << "No data file found!" << endl;
        return -1;
    }

    //fill the table with data
    fillTable();

    //print the table
    cout    << table << endl;
    outFile << table << endl;

    //print some stats
    cout    << "table size = " << table.size() << endl;
    outFile << "table size = " << table.size() << endl;

    cout    << "num data holes = " << table.getNumDataHoles()  << endl;
    outFile << "num data holes = " << table.getNumDataHoles()  << endl;

    cout    << "num collisions = " << table.getNumCollisions() << endl;
    outFile << "num collisions = " << table.getNumCollisions() << endl;

    //find a student
    Student *mighty = NULL;

    if(table.isPresent("Mighty Mouse"))
    {
        cout    << "Mighty Mouse is in the list" << endl;
        outFile << "Mighty Mouse is in the list" << endl;
        mighty = table.getElement("Mighty Mouse");
        if(NULL == mighty)
        {
            cout    << "Failed to get item Mighty Mouse" << endl;
            outFile << "Failed to get item Mighty Mouse" << endl;
        }
        else
        {
            cout    << "His phone number is " << mighty->phoneNumber << endl;
            outFile << "His phone number is " << mighty->phoneNumber << endl;
        }
        
        //remove a student
        cout    << "removing Mighty Mouse" << endl;
        outFile << "removing Mighty Mouse" << endl;
        table.remove("Mighty Mouse");

        if(table.isPresent("Mighty Mouse"))
        {
            cout << "failed to remove Mighty Mouse" << endl;
            outFile << "failed to remove Mighty Mouse" << endl;
        }
        else
        {
            cout    << "succesfully removed Mighty Mouse" << endl;
            outFile << "succesfully removed Mighty Mouse" << endl;
        }
    }

    //reprint size after removal
    cout    << "Now table size is " << table.size() << endl;
    outFile << "Now table size is " << table.size() << endl;

    //search for student not in the table
    if(table.isPresent("Heather Wood"))
    {
        cout    << "Somenow my wife ended up in this table." << endl;
        outFile << "Somenow my wife ended up in this table." << endl;
    }
    else
    {
        cout    << "seems the lookup function works right." << endl;
        outFile << "seems the lookup function works right." << endl;
    }

    outFile.close();

    return 0;
}
