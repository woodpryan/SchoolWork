/*  Assignment: Name Grade Sorted Link List
    Author:     Ryan Wood
    Created On: February 12, 2018
*/
/*Student Linked List Main test file*/

#include "../LinkedList/Student.h"
#include "../LinkedList/LinkedList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const string fileName = "../LinkedList/LinkLnamesAndGrades.txt";

ifstream inFile(fileName);//set up an input file

//set up a structure to hold student info from the file
struct RimesStudent
{
    string name;
    int    gradeTotal;
    double gradeValue;
};

int NUM_STUDENTS = 0;
int MAX_POINTS   = 0;

/*  Function:   countStudents()
    Purpose:    this function loops through the lines of
                the input file and counts the number of
                lines that are not the first or not students.
    Return:     the number of students whose data is defined in the file
*/
int countStudents()
{
    int    num = 0;
    string strName;

    while(getline(inFile, strName, '\n'))
    {
        if(strName.length() > 1)
            num++;
    }
    num--;/*minus one because first newline comes after 
            the first line, which is total possible points*/
    return num;
}

/*  Function:   fillArray(RimesStudent[])
    Purpose:    fills the given array of RimesStudents with data
                from the file. The array is assumed to have as many
                elements as the global NUM_STUDENTS variable
    Parameters: the empty array of students
    PostCond:   the array is filled with data from the file
*/
void fillArray(RimesStudent students[])
{
    int           iGrade  = 0;
    double        dGrade  = 0.0;
    string        strName = "";
    RimesStudent *iter    = NULL;

    inFile >> MAX_POINTS;
    if(MAX_POINTS == 0)
    {
        cout << "Could not obtain the Maximum number of points from the file!" << endl;
        return;
    }
    cout << MAX_POINTS << endl;
    cout << "Maximum points possible = " << MAX_POINTS << endl;
    iter = students;
    while(inFile >> strName >> iGrade)
    {
        iter->name = strName;
        iter->gradeTotal = iGrade;
        iter->gradeValue = ((double) iGrade/MAX_POINTS)*100;

        iter++;
    }
}

/*  Function:   testLinkedList(RimesStudent[])
    Purpose:    This function goes through the given array of
                students and insert each of them into a LinkedList
                which it then prints in name and grade order and then
                prints only the student who made A's in order of their
                grades
    Parameters: the array of Rimes Student structures
*/
void testLinkedList(RimesStudent students[])
{
    int          count = 0;
    RimesStudent *iter = NULL;
    LinkedList   *studentList = new LinkedList;
    
    iter = students;
    for(count = 0; count < NUM_STUDENTS; count++)
    {
        studentList->insert(iter->name, iter->gradeValue);
        iter++;
    }
    /*
    cout << "Printing list in name order" << endl;
    studentList->print();

    cout << "Printing List in Grade order" << endl;
    studentList->printByGrade();

    cout << "Printing all A students" << endl;
    studentList->printAStudents();
    */

    cout << "Printing in reverse" << endl;
    studentList->printReverse();

    delete(studentList);
}

/*
int main()
{
    //how manu students do we have
    NUM_STUDENTS = countStudents();

    //create a RimesStudent array with that many
    RimesStudent students[NUM_STUDENTS];

    //now that we are at the end of the file, re-initialize it
    inFile.close();
    inFile.open(fileName);

    //fill the array with data from the file
    fillArray(students);

    //create a LinkedList from the students and test functions
    testLinkedList(students);

    inFile.close();

    return 0;
}
*/
