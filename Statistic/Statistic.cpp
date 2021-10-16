#include "Statistic.h"
/*  Assignment:     Statistician Program
    Author:         Ryan Wood
    Date Created:   January  14, 2018
    Requirements:   Create a Statistic class that recieves numerical input
                    and calculates how many values have been input, the average
                    of all the values, the total of all the values, the largest
                    and smallest values, and allows the statistic to be cleared
                    for reuse
*/
/*Statistic implementation file*/

Statistic::Statistic()
{
    m_smallest = 0.0;
    m_largest = 0.0;
    m_valTotal = 0.0;
    m_numVals = 0;
}

void Statistic::initStat()
{
    m_smallest = 0.0;
    m_largest = 0.0;
    m_valTotal = 0.0;
    m_numVals = 0;
}

void Statistic::add(double val)
{
    m_smallest = smallest(val, m_smallest);
    m_largest = largest(val, m_largest);
    m_valTotal += val;
    m_numVals++;
}

int Statistic::getLength()
{
    return m_numVals;
}

double Statistic::getSum()
{
    return m_valTotal;
}

double Statistic::getAverage()
{
    return m_valTotal / m_numVals;
}

double Statistic::getLargest()
{
    return m_largest;
}

double Statistic::getSmallest()
{
    return m_smallest;
}

double Statistic::largest(double val1, double val2)
{
    if(val1 > val2)
        return val1;

    return val2;
}

double Statistic::smallest(double val1, double val2)
{
    if(val1 < val2)
        return val1;

    return val2;
}

