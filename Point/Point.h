/*  Assignment:     Points Class
    Requirements:   implement the Point class from the book
                    Data Structures and Other Objects Using C++ by
                    Main and Savitch, and add the methods
                    translate, scale, rotate, and shear
    Author:         Ryan Wood
    Created On:     January 21, 2018
    Updated On:     January 28, 2018
*/
/*Point Header file*/
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>

class Point
{
    public:

        /*  Function:   Point()
            Purpose:    default constructor. Initializes x and y
                        coordinates to 0
            Return:     a Point instance
        */
        Point();

        /*  Function:   Point(double, double)
            Purpose:    constructore for the Point class. initializes
                        x to dXpos and y to dYpos
            Parameters: the x and y positions
            Return:     an instance of a Point
        */
        Point(double dXpos, double dYpos);
    
        /*  Function:   shift(double, double)
            Purpose:    moves the point by the given x amount and the
                        given y amount along their respective axis
            Parameters: the x amount to shift,
                        the y amount to shift
        */
        void shift(double xAmount, double yAmount);

        /*  Function:   rotate90()
            Purpose:    rotates the Point clockwise by 90 degreees
        */
        void rotate90();

        /*  Function:   getX() const
            Purpose:    retrieves the Point's value for the x coordinate
            Return:     the x coordinate
        */
        double getX() const;

        /*  Function:   getY()
            Purpose:    retrieves the value for the Point's y coordinate
            Return:     the y coordinate
        */
        double getY() const;

        /*  Function:   translate(double, double)
            Purpose:    this function does the same thing as function shift,
                        adding the given x and y amounts respectively to
                        the x and y coordinates of the point
            Parameters: the x amount to move, the y amount to move
        */
        void translate(double, double);

        /*  Function:   scale(double, double)
            Purpose:    multiplies the x and y coordinates of the point by
                        the given amount for x and y respectively
            Parameters: the x amount to scale, the y amounbt to scale
        */
        void scale(double, double);

        /*  Function:   rotate(double)
            Purpose:    rotates the point by the given amount of degrees
            Parameters: the amount in degrees to rotate
        */
        void rotate(double);
        
        /*  Function:   shearX(double)
            Purpose:    shifts x by the given amount along the x axis
            Parameters: the amount to shift along the x axis
        */
        void shearX(double);

        /*  Function:   shearY(double)
            Purpose:    shifts the point's y coordinate by the given amount
            Parameters: the amount to shift along the y axis
        */
        void shearY(double);

        /*  Function:   operator <<(istream&, Point&)
            Purpose:    overloads the input operator, setting the x and
                        y member variables of the given Point to be the
                        next two double values given to the input stream
            Parameters: a reference to the input stream, a reference to the Point
            Return:     a reference to the input stream
        */
        friend std::istream& operator >>(std::istream &in, Point &target);


    private:

        double getRadians(double degrees) const;

        double x;
        double y;
};

/*  Function:   distance(const Point&, const Point&)
    Purpose:    determines the distance between the two
                given points using pythagorean's theorem
    Parameters: the first point, the second point
    Return:     the distance between the points
*/
double distance(const Point &pntA, const Point &pntB);

/*  Function:   middle(const Point&, const Point&)
    Purpose:    determines the midpoint between the given points,
                constructs a Point object having those coordinates
                and returns it
    Parameters: the first point, the second point
    Return:     the Point in the middle
*/
Point middle(const Point &pntA, const Point &pntB);


/*  Function:   operator ==(const Point&, const Point&)
    Purpose:    determines whether the given points are equal,
                overloading the == operator
    Parameters: the first point, the second point
    Return:     whether the points have the same coordinates
*/
bool operator ==(const Point &pntA, const Point &pntB);

/*  Function:   operator !=(const Point&, const Point&)
    Purpose:    determines whetheer the given points are not equal,
                overloading the != operator
    Parameters: the first point, the second point
    Return:     whether the two points do not hae the same coordinates
*/
bool operator !=(const Point &pntA, const Point &pntB);

/*  Function:   operator +(const Point, const Point)
    Purpose:    adds the x and y coordinates of the two given points,
                and constructs a point having the new coordinates,
                overloading the + operator
    Parameters: the first point, the second point
    Return:     A point having coordinates that are the sum of the given points
*/
Point operator +(const Point &pntA, const Point &pntB);

/*  Function:   operator -(const Point&, const Point&)
    Purpose:    subtracts pointB from pointA and returns
                a new point with the x and y values
                having the results
    Paramters:  the first point, the second point
    Return:     the subtraction result Point instance
*/
Point operator -(const Point &pntA, const Point &pntB);

/*  Function:   operator >(const Point &, const Point&)
    Purpose:    determines whether the first point is
                farther from the origin Point(0,0) than
                the second point.
    Parameters: the first point, the second point
    Return:     whether the first point is futher from 0,0
*/
bool operator >(const Point &pntA, const Point &pntB);

/*  Function:   operator <(const Point &, const Point&)
    Purpose:    determines whether the first point is
                closer to the origin Point(0,0) than
                the second point.
    Parameters: the first point, the second point
    Return:     whether the first point is closer to 0,0
*/
bool operator <(const Point &pntA, const Point & pntB);

/*  Function:   operator <=(const Point&, const Point&)
    Purpose:    determines whether the first point is
                either equal to the second point or closer
                to the origin than the second point
    Paramters:  the first point, the second point
    Return:     whether the points are equal or 
                the first point is less than the second point
*/
bool operator <=(const Point &pntA, const Point &pntB);

/*  Function:   operator >=(const Point&, const Point&)
    Purpose:    determines whether the first point is
                either equal to the second point or further
                from the origin than the second point
    Paramters:  the first point, the second point
    Return:     whether the points are equal or 
                the first point is greater than the second point
*/
bool operator >=(const Point &pntA, const Point &pntB);

/*  Function:   operator <<(ostream&, Point)
    Purpose:    overloads the output operator and outputs
                the x and y coordnates formatted to "(x, y)"
    Parameters: a reference to the output stream, the Point to print
    Return:     a reference to the output stream
*/
std::ostream& operator <<(std::ostream &out, const Point &source);

/*  Function:   operator <<(ofstream&, Point)
    Purpose:    overloads the insertion operator using the ofstream
                data output to file provided as the first argument.
                Writes the given point to the file in format "(x, y)"
    Parameters: a reference to the file output stream, the Point to write
    Return:     a reference to the file output stream
*/
std::ofstream& operator <<(std::ofstream &out, const Point &source);

#endif
