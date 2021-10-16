#include<iostream>
#include<string>

#include "Student.h"
#include "LinkedList.h"
#include <fstream>

ofstream outFile("output.out");

using namespace std;

int main()
{
    cout << "Hello from main" << endl;
    LinkedList<Student, 10> list;

    cout << "created list" << endl;
    Student *stud = new Student;

    cout << "Created student" << endl;

    stud->name = "Ryan";
    stud->key = "Ryan";
    stud->phoneNumber = "698-5448";
    list.insert(stud);
    
    Student *studC = new Student();
    studC->name        = "Heather";
    studC->key = "Heather";
    studC->phoneNumber = "617-3796";
    list.insert(studC);

    Student *studB = new Student();
    studB->name = "Mike";
    studB->key = "Mike";
    studB->phoneNumber = "867-5309";
    list.insert(studB);


    Student *studD = new Student();
    studD->name = "Aaron";
    studD->key = "Aaron";
    studD->phoneNumber = "340-1839";
    list.insert(studD);
    cout << list.size() << endl;
    list.print();

    if(studD > studB)
        cout << *studD << " is less than " << *studB << endl;
    else
        cout << *studD << " is greater than " << *studB << endl;

    Student *studentF = new Student();

    studentF = list.find("Aaron");
    if(NULL != studentF)
        list.remove(studentF);

        
    cout << "hello" << endl;
    list.print();
    cout << endl;

    cout << list.size() << endl;

    outFile.close();
    return 0;
}
