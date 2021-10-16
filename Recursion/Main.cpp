/*  Assignment:     Recursion Exercises
    Author:         Ryan Wood
    Created On:     March 18, 2018
    Purpose:        demonstrate an understanding of the power
                    of recursive functions through a
                    series of exercises
*/

#include <iostream>
#include <fstream>
#include "LinkedListStudentMain.h"

using namespace std;

ofstream outStream("Recursion.out");

int hailstone(int num)
{
    cout << num << ", ";
    if(num <= 1)
        return 1;
    else if(num % 2 == 0)
        num /= 2;
    else
    {
        num *= 3;
        num++;
    }

    return hailstone(num);
}

void fillIntArray(int *arry, size_t size, int val)
{
    if(size <= 0)
        return;

    fillIntArray(++arry,--size, ++val);
    *arry = val;
}

void fillIntArrayReverse(int *arry, size_t size, int val)
{
    if(size <= 0)
        return;

    *arry = val;
    fillIntArrayReverse(++arry,--size, --val);
}

void printIntArray(int *arry, size_t size)
{
    if(size <= 0)
        return;
    cout      << *arry << ", ";
    outStream << *arry << ", ";
    printIntArray(++arry, --size);
}

void fillArrayMiddleOut(int *arry, size_t size)
{
    int val = size;

    if(size <= 0)
        return;
    else if(size % 2 == 0)
    {
        *arry = val;
        fillArrayMiddleOut(++arry, --size);
    }
    else
    {
        fillArrayMiddleOut(++arry, --size);
        *arry = val;
    }
}

int main()
{
    int  num   = 1839;
    int  count = 0;
    int *arry  = NULL;
    int *arry2 = NULL;
    int *arry3 = NULL;

    //how many students do we have
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

    count = hailstone(num);
    cout      << endl << endl;
    outStream << endl << endl;

    arry = new int[22];
    fillIntArray(arry, 22, 0);
    printIntArray(arry, 22);
    cout      << endl << endl;
    outStream << endl << endl;

    arry2 = new int[22];
    fillIntArrayReverse(arry2, 22, 22);
    printIntArray(arry2, 22);

    cout      << endl << endl;
    outStream << endl << endl;

    inFile.close();
    outStream.close();

    arry3 = new int[13];
    fillArrayMiddleOut(arry3, 13);
    printIntArray(arry3, 13);
    cout      << endl << endl;
    outStream << endl << endl;

    delete arry;
    delete arry2;
    delete arry3;

    outStream.close();

    return 0;
}

