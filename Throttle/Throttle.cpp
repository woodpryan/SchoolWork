#include "Throttle.h"
#include <iostream>

/*  Assignment:     Throttle Class
    Author:         Ryan Wood
    Date Created:   January 13, 2018
    Requirements:   implement the Throttle class from the book 
                    with the addition of a maximum throttle amount
*/
/*Throttle class implementation file*/

using namespace std;

Throttle::Throttle()
{
    maxPosition = 6;
    curPosition = 0;
}

Throttle::Throttle(int max)
{
    if(max > 0)
        maxPosition = max;
    else
        maxPosition = 1;
    curPosition = 0;
}


Throttle::Throttle(int cur, int max)
{
    if(max <= 0)
        maxPosition = 6;
    else
        maxPosition = max;

    if(cur < 0)
        curPosition = 0;
    else if(cur > max)
        curPosition = max;
    else
        curPosition = cur;
}

void Throttle::shutOff()
{
    curPosition = 0;
}

void Throttle::shift(int amount)
{
    curPosition+= amount;

    if(curPosition > maxPosition)
        curPosition = maxPosition;
    if(curPosition < 0)
        curPosition = 0;
}

bool Throttle::isOn()
{
    return (curPosition > 0);
}

double Throttle::flow()
{
    double dFlow = 0.0;
    
    dFlow = double (curPosition) / maxPosition;

    dFlow *= 100;

    return dFlow;
}
