/*  Assignment:     Name Grade Sorted Link List
    Author:         Ryan Wood
    Created On:     February 11, 2018
    Purpose:        demonstrate use of Linked List structure
*/
/*Student structure*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/*the Student structure for our Linked List*/
struct Student
{
    std::string   name;
    double        grade;
    Student      *nameLink;//Link to order list by name
    Student      *gradeLink;//link to order list by grade
    Student      *aStudentLink;//link to order list by A students only
};

typedef Student* node;//make the Student pointer easier to deal with

#endif
