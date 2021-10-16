/*  Assignment:     Name Grade Sorted Link List
    Author:         Ryan Wood
    Created On:     February 11, 2018
    Purpose:        demonstrate use of Linked List structure
*/
/*Linked List implementation file*/


#include "Student.h"
#include "LinkedList.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

ofstream outFile;

LinkedList::LinkedList()
{
    head = NULL;
    outFile.open("StudentOutput.out");
    outFile << fixed << showpoint << setprecision(2);
    cout << fixed << showpoint << setprecision(2);
}

LinkedList::~LinkedList()
{
    outFile.close();
}

int LinkedList::getNumNodes()
{
    int  total       = 0;
    node nodePointer = NULL;

    nodePointer = head;
    while(nodePointer)
    {
        total++;
        nodePointer = nodePointer->nameLink;
    }

    return total;
}

void LinkedList::insert(string name, double grade)
{
    node newNode  = NULL;
    node nodePtr  = NULL;
    node prevNode = NULL;
    node aStudnt  = NULL;
    node prevA    = NULL;

    newNode            = new Student;
    newNode->name      = name;
    newNode->grade     = grade;
    newNode->nameLink  = NULL;
    newNode->gradeLink = NULL;
    
    if(NULL == head)
    {
        head = new Student;
        head->grade = 0.0;
        head->name = "";
        head->gradeLink = NULL;
        head->aStudentLink = NULL;
    }

    nodePtr = head->nameLink;

    while(NULL != nodePtr && nodePtr->name < name)
    {
        prevNode = nodePtr;
        nodePtr = nodePtr->nameLink;
    }
    
    newNode->nameLink = nodePtr;
    if(NULL == prevNode)
    {
        head->nameLink = newNode;
    }
    else
        prevNode->nameLink = newNode;

    //reset vars
    prevNode = NULL;
    nodePtr  = head->gradeLink;
    while(NULL != nodePtr && nodePtr->grade >= grade)
    {
        prevNode = nodePtr;
        nodePtr = nodePtr->gradeLink;
    }
    
    newNode->gradeLink = nodePtr;

    if(NULL != prevNode)
        prevNode->gradeLink = newNode;
    else
        head->gradeLink = newNode;

    if(grade >= 90)//check a student Links
    {
        //reset vars
        prevNode = NULL;
        nodePtr = head->aStudentLink;
        while(NULL != nodePtr && nodePtr->grade >= grade)
        {
            prevNode = nodePtr;
            nodePtr  = nodePtr->aStudentLink;
        }

        newNode->aStudentLink = nodePtr;
        if(NULL != prevNode)
            prevNode->aStudentLink = newNode;
        else
            head->aStudentLink = newNode;
        
    }
}

void LinkedList::print()
{
    node nodePtr = NULL;

    cout    << "Printing students by name" << endl;
    outFile << "Printing students by name" << endl;
    nodePtr = head->nameLink;
    while(NULL != nodePtr)
    {
        cout    << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
        outFile << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;

        nodePtr = nodePtr->nameLink;
    }
    cout << endl;
    outFile << endl;
}

void LinkedList::printReverse(node nodePtr)
{
    if(NULL == nodePtr)
    {
        cout    << "Printing students by name" << endl;
        outFile << "Printing students by name" << endl;
        return;
    }
    else
        printReverse(nodePtr->nameLink);

    cout    << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
    outFile << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
    nodePtr = nodePtr->nameLink;
}

void LinkedList::printReverse()
{
    if(NULL != head)
        printReverse(head->nameLink);
}

void LinkedList::printByGrade()
{
    node nodePtr = NULL;

    cout    << "Printing students by grade" << endl;
    outFile << "Printing students by grade" << endl;
    nodePtr = head->gradeLink;
    while(NULL != nodePtr)
    {
        cout    << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
        outFile << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
        nodePtr = nodePtr->gradeLink;
    }
    cout << endl;
    outFile << endl;
}

void LinkedList::printAStudents()
{
    node nodePtr = NULL;

    cout    << "Printing A students only by grade" << endl;
    outFile << "Printing A students only by grade" << endl;
    nodePtr = head->aStudentLink;
    while(NULL != nodePtr && nodePtr->grade >= 90)
    {
        cout    << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
        outFile << left << setw(15) << nodePtr->name << setw(15) << nodePtr->grade << endl;
        nodePtr = nodePtr->aStudentLink;
    }
    cout << endl;
    outFile << endl;
}

