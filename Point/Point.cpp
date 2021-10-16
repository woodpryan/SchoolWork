/*  Assignment:     Points Class
    Requirements:   implement the Point class from the book
                    Data Structures and Other Objects Using C++ by
                    Main and Savitch, and add the methods
                    translate, scale, rotate, and shear
    Author:         Ryan Wood
    Created On:     January 21, 2018
    Updated On:     January 28, 2018
*/
/* Point class implementation file*/

#include "Point.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const double PI = 3.1415;

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double dXpos, double dYpos)
{
    x = dXpos;
    y = dYpos;
}
    
void Point::shift(double xAmount, double yAmount)
{
    x+= xAmount;
    y+= yAmount;
}

void Point::rotate90()
{
    double tmpX = 0.0;
    double tmpY = 0.0;

    tmpX = y;
    tmpY = -x;

    x = tmpX;
    y = tmpY;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::translate(double dXval, double dYval)
{
    shift(dXval, dYval);
}

void Point::scale(double dXval, double dYval)
{
    x*= dXval;
    y*= dYval;
}

void Point::rotate(double degrees)
{
    double sinDeg  = 0.0;
    double cosDeg  = 0.0;
    double radians = 0.0;
    double tmpX    = 0.0;
    double tmpY    = 0.0;

    radians = getRadians(degrees);

    tmpX = (x * cos(radians) - y * sin(radians));
    tmpY = (x * sin(radians) - y * cos(radians));

    x = tmpX;
    y = tmpY;
}
        
void Point::shearX(double dAmount)
{
    x+= dAmount;
}

void Point::shearY(double dAmount)
{
    y+= dAmount;
}

double Point::getRadians(double degrees) const
{
    double radians = 0.0;

    radians = (degrees * PI) / 180 ;

    return radians;
}

double distance(const Point &pntA, const Point &pntB)
{
    double a  = 0.0;
    double b  = 0.0;
    double c2 = 0.0;

    a = pntA.getX() - pntB.getX();
    b = pntA.getY() - pntB.getY();

    //pythagorean theorem calculates the square of the distance between the points
    c2 = (a*a) + (b*b);

    return sqrt(c2);
}

Point middle(const Point &pntA, const Point &pntB)
{
    double xMid = 0.0;
    double yMid = 0.0;

    xMid = (pntA.getX() + pntB.getX()) /2;
    yMid = (pntA.getY() + pntB.getY()) /2;

    Point mid(xMid, yMid);

    return mid;
}

bool operator ==(const Point &pntA, const Point &pntB)
{
    bool isEqual = false;
    
    if(pntA.getX() == pntB.getX() &&
       pntA.getY() == pntB.getY())
        isEqual = true;

    return isEqual;
}

bool operator !=(const Point &pntA, const Point &pntB)
{
    return !(pntA == pntB);
}

Point operator +(const Point &pntA, const Point &pntB)
{
    double xSum = 0.0;
    double ySum = 0.0;

    xSum = pntA.getX() + pntB.getX();
    ySum = pntA.getY() + pntB.getY();

    Point sum(xSum, ySum);

    return sum;
}

Point operator -(const Point &pntA, const Point &pntB)
{
    double xDiff = 0.0;
    double yDiff = 0.0;

    xDiff = pntA.getX() - pntB.getX();
    yDiff = pntA.getY() - pntB.getY();

    Point diff(xDiff, yDiff);

    return diff;
}

bool operator >(const Point &pntA, const Point &pntB)
{
    double distA = 0.0;
    double distB = 0.0;

    Point origin(0,0);

    distA = distance(pntA, origin);
    distB = distance(pntB, origin);

    return (distA > distB);
    
}

bool operator <(const Point &pntA, const Point & pntB)
{
    double distA = 0.0;
    double distB = 0.0;

    Point origin(0, 0);
    
    distA = distance(pntA, origin);
    distB = distance(pntB, origin);

    return (distA < distB);
}

bool operator <=(const Point &pntA, const Point &pntB)
{
    return ((pntA < pntB) || pntA == pntB);
}

bool operator >=(const Point &pntA, const Point &pntB)
{
    return ((pntA > pntB) || pntA == pntB);
}

ostream& operator <<(ostream &out, const Point &source)
{
    out << "(" << source.getX() << ", " << source.getY() << ")";
    return out;
}

istream& operator >>(istream &in, Point &target)
{
    in >> target.x >> target.y;
    return in;
}

ofstream& operator <<(ofstream &out, const Point &source)
{
    out << "(" << source.getX() << ", " << source.getY() << ")";
    return out;
}
