/*  Assignment:     Hash Table
    Author:         Ryan Wood
    Created On:     April 14, 2018
*/
/*Student*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>

/*the Student structure for our Linked List*/
class Student
{
    /* What I really want is a stuct, so I'm making members public,
       but I also want to easilly associate the name with the key,
       so I wrote the constructor function, I want to be able to
       easily compare so I wrote the comparison functions,
       I want to be able to easily copy a student so I
       overloaded the equal operator, and I want to be able to
       easilly output to a file or the console so I overloaded the
       insertion operator
    */

    public:
        std::string   name;
        std::string   key;
        std::string   phoneNumber;
        Student      *nodeLink;//Link to order list by name

        /*  Function:   Student(string, string)
            Purpose:    creates a student having the given name
                        and phone number, sets the key variable
                        to the value of name, and sets the nodeLink NULL
            Parameters: the name, the phone number
            Return:     a student instance
        */
        Student(std::string strName, std::string strPhone)
        {
            name        = strName;
            key         = strName;
            phoneNumber = strPhone;
            nodeLink    = NULL;
        }

        /*  Function:   Student()
            Purpose:    sets the nodeLink variable NULL
            Return:     an empty student
        */
        Student()
        {
            nodeLink = NULL;
        }

        /*  Function:   operator =(Student)
            Purpose:    sets this student's member variables to be
                        the values of the given student's
                        member variables (copy)
            Parameters: the other student
        */
        void operator = (const Student &stud)
        {
            nodeLink    = stud.nodeLink;
            key         = stud.key;
            name        = stud.name;
            phoneNumber = stud.phoneNumber;
        }

        /*  Function:   operator >(const Student&) const
            Purpose:    determines whether the given student has a
                        name variable value that is less than this
                        student's name variable value
            Parameters: the other student
            Return:     whether the other student is less 
        */
        bool operator >(const Student &stud) const
        {
            return name > stud.name;
        } 

        /*  Function:   operator <(const Student &) const
            Purpose:    determines whether the given student has a
                        name variable value that is greater then this
                        student's name variable value
            Parameters: the other student
            Return:     whether the other student is greater
        */
        bool operator <(const Student &stud) const
        {
            return name < stud.name;
        }

        /*  Function:   operator ==(const Student &) const
            Purpose:    determines whether the given student has
                        the same name variable value as this student
            Parameters: the student
            Return:     whether the students are equal
        */
        bool operator ==(const Student &stud) const
        {
            return name == stud.name;
        }

        /*  Function:   operator <<(ofstream&, const Student)
            Purpose:    outputs the given student using the given file output stream
                        printing the name followed by a colon, followed by the
                        student phone number to the file
            Parameters: the file stream, the student
            Return:     the file stream
        */
        friend std::ofstream& operator <<(std::ofstream& out, const Student &student)
        {
            out.flush();
            out << student.name << " : " << student.phoneNumber;
            return out;
        }

        /*  Function:   operator <<(ostream&, const Student &)
            Purpose:    outputs the given student using the given output stream,
                        printing the name followed by a colon, followed by the
                        student phone number
            Parameters: the output stream, the student
            Return:     the output stream
        */
        friend std::ostream& operator <<(std::ostream& out, const Student &student)
        {
            out.flush();
            out << student.name << " : " << student.phoneNumber;
            return out;
        }
};

#endif
