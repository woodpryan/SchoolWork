/*  Assignment:     Statistician Program
    Author:         Ryan Wood
    Date Created:   January  14, 2018
    Requirements:   Create a Statistic class that recieves numerical input
                    and calculates how many values have been input, the average
                    of all the values, the total of all the values, the largest
                    and smallest values, and allows the statistic to be cleared
                    for reuse
*/
/*Statistic Main file*/

#include "Statistic.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream outFile("Statistics.out");

int main()
{
    Statistic stat;
    Statistic stat2;

    stat.add(52.5);
    stat.add(65.6);
    stat.add(87.8);
    stat.add(-35.4);
    stat.add(-10.5);
    stat.add(4.7);
    stat.add(90.1);

    outFile << "sum stat1 = " << stat.getSum() << endl;
    outFile << "length of stat1 = " << stat.getLength() << endl;
    outFile << "stat1 value average = " << stat.getAverage() << endl;
    outFile << endl;

    stat2.add(203);
    stat2.add(421);
    stat2.add(571);
    stat2.add(487);
    stat2.add(312);
    stat2.add(445);
    stat2.add(624);
    stat2.add(623);
    stat2.add(324);
    stat2.add(732);

    outFile << "sum stat2 = " << stat2.getSum() << endl;
    outFile << "length of stat2 = " << stat2.getLength() << endl;
    outFile << "stat2 value average = " << stat2.getAverage() << endl << endl;

    stat2.initStat();

    stat2.add(99.3);
    stat2.add(-69.3);
    stat2.add(83.2);
    stat2.add(78.2);
    stat2.add(88.2);
    stat2.add(83.8);
    stat2.add(77.2);
    stat2.add(-39.2);
    stat2.add(76.6);
    stat2.add(96.3);

    outFile << endl;

    outFile << "Cleared stat2 and added new values" << endl;

    outFile << "sum stat2 = " << stat2.getSum() << endl;
    outFile << "length of stat2 = " << stat2.getLength() << endl;
    outFile << "stat2 value average = " << stat2.getAverage() << endl;

    outFile << "stat2 largest = " << stat2.getLargest() << endl;
    outFile << "stat2 smallest = " << stat2.getSmallest() << endl;

    outFile.close();

    return 0;
}
