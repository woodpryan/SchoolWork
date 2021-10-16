/*  Assignment:     Points Class
    Requirements:   implement the Point class from the book
                    Data Structures and Other Objects Using C++ by
                    Main and Savitch, and add the methods
                    translate, scale, rotate, and shear
    Author:         Ryan Wood
    Created On:     January 21, 2018
    Updated On:     January 28, 2018
*/
/* Point class Main test file*/

#include "Point.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

ofstream outFile("Point.out");

int main()
{
    outFile << showpoint << setprecision(2);
    /**************************************************
    Requirement 1. set up box with four points:
                   (2,2), (2, 5), (4, 5), (4, 2)
                   and print out the points
    *****************************************************/
    Point point1(2, 2);
    Point point2(2, 5);
    Point point3(4, 5);
    Point point4(4, 2);

    outFile << point1 << endl;
    outFile << point2 << endl;
    outFile << point3 << endl;
    outFile << point4 << endl << endl;

    /**** Requirement 2. translate x = 2 and y = 1 distance ******/
    point1.translate(2, 1);
    point2.translate(2, 1);
    point3.translate(2, 1);
    point4.translate(2, 1);

    outFile << "Translated by x = 2, y = 1" << endl;
    outFile << point1 << endl;
    outFile << point2 << endl;
    outFile << point3 << endl;
    outFile << point4 << endl << endl;

    /******* Requirement 3. scale box by x = 2 and y = 0.5 ********/
    point1.scale(2, 0.5);
    point2.scale(2, 0.5);
    point3.scale(2, 0.5);
    point4.scale(2, 0.5);

    outFile << "Scaled by x = 2 and y = 0.5" << endl;
    outFile << point1 << endl;
    outFile << point2 << endl;
    outFile << point3 << endl;
    outFile << point4 << endl << endl;
    
    /****** Requirement 4. Using original box point values, rotate 30 degrees,
                            then rotate another 60 degrees**************/
    Point point5(2, 2);
    Point point6(2, 5);
    Point point7(4, 5);
    Point point8(4, 2);

    point5.rotate(30);
    point6.rotate(30);
    point7.rotate(30);
    point8.rotate(30);

    outFile << "Original box rotated 30 degrees" << endl;
    outFile << point5 << endl;
    outFile << point6 << endl;
    outFile << point7 << endl;
    outFile << point8 << endl << endl;

    point5.rotate(60);
    point6.rotate(60);
    point7.rotate(60);
    point8.rotate(60);

    outFile << "Box rotated another 60 degrees" << endl;
    outFile << point5 << endl;
    outFile << point6 << endl;
    outFile << point7 << endl;
    outFile << point8 << endl << endl;

    /***** Requirement 5. shear in x direction 1.5 ******/
    point5.shearX(1.5);
    point6.shearX(1.5);
    point7.shearX(1.5);
    point8.shearX(1.5);

    outFile << "Box sheared by x = 1.5" << endl;
    outFile << point5 << endl;
    outFile << point6 << endl;
    outFile << point7 << endl;
    outFile << point8 << endl << endl;

    /****** Requirement 6. shear in y direction 1.7*******/
    point5.shearY(1.7);
    point6.shearY(1.7);
    point7.shearY(1.7);
    point8.shearY(1.7);

    outFile << "Box sheared by y = 1.7" << endl;
    outFile << point5 << endl;
    outFile << point6 << endl;
    outFile << point7 << endl;
    outFile << point8 << endl << endl;

    /********* Requirement 7. Test functions from the book for Point ****/
    Point ryansPoint(1, 2.5);
    Point joesPoint(-3, -7.3);

    //shift test
    outFile << "Ryan's point = " << ryansPoint << endl;
    outFile << "Joe's Point = " << joesPoint << endl;
    ryansPoint.shift(-2, 2);

    //add two points test
    outFile << "Ryan's Point shifted by (x = -1, y = 2) = " << ryansPoint << endl;
    Point ryanAndJoePoint = ryansPoint + joesPoint;

    outFile << "Ryan and Joe's Points added = " << endl;
    outFile << ryansPoint << " + " << joesPoint << " = " << ryanAndJoePoint << endl << endl;

    //rotate90 function test
    ryansPoint.rotate90();
    outFile << "Ryan's point rotated 90 degrees = " << ryansPoint << endl << endl;

    ryansPoint.rotate90();
    outFile << "Ryan's point rotated another 90 degrees = " << ryansPoint << endl << endl;

    //middle function test
    outFile << "Joe's Point = " << joesPoint << " and Ryan's Point = " << ryansPoint << endl;
    Point midPoint = middle(joesPoint, ryansPoint);
    outFile << "The midpoint between these points is " << midPoint << endl;

    //distance function test
    outFile << "The distance between Ryan and Joes Points is " << distance(ryansPoint, joesPoint) << endl << endl;

    Point newPoint(4, 5);
    Point otherPoint(4, 5);

    //equality operator test
    if(newPoint == otherPoint)
        outFile << "newPoint and otherPoint are equal" << endl;
    else
        outFile << "== function not working " << endl;

    //less than or equal to operator test
    if(newPoint <= otherPoint)
        outFile << "newPoint is less than or equal to otherPoint" << endl;
    else
        outFile << "<= function not working " << endl;

    //shift point by 1
    outFile << "otherPoint shifted by 1" << endl;
    otherPoint.shift(1, 1);

    //not equal operator test
    if(newPoint != otherPoint)
        outFile << "newPoint is now not equal to otherPoint" << endl;
    else
        outFile << "!- function not working" << endl;

    //greater than or equal to operator test
    if(otherPoint >= newPoint)
        outFile << "otherPoint is greater than or equal to newPoint" << endl;
    else
        outFile << ">= function not working" << endl;

    outFile.close();

    return 0;
}

