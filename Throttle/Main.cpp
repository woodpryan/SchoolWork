/*  Assignment:     Throttle Class
    Author:         Ryan Wood
    Date Created:   January 13, 2018
    Requirements:   implement the Throttle class from the book 
                    with the addition of a maximum throttle amount
*/
/*Throttle class test Main file*/

#include "Throttle.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream outFile("Throttle.out");

int main()
{
    bool     isOn  = false;
    double   dFlow = 0.0;

    outFile << showpoint << setprecision(4); 

    Throttle thCar;
    Throttle thRig(30);
    Throttle thShuttle(4, 20);

    isOn = thCar.isOn();
    outFile << "Car is on before shift = " << isOn << endl;
    thCar.shift(1);
    isOn = thCar.isOn();
    outFile << "Car is on after shift = " << isOn << endl;

    dFlow = thCar.flow();
    outFile << "Car flow at first gear = " << dFlow << "\%" <<endl;
    thCar.shift(4);

    dFlow = thCar.flow();
    outFile << "car flow at 5th gear = " << dFlow << "\%" << endl;

    thCar.shift(-1);
    dFlow = thCar.flow();
    outFile << "Car flow at 4th gear = " << dFlow << "\%" << endl;

    thRig.shift(15);

    dFlow = thRig.flow();
    outFile << "rig flow shifted to 15th gear = " << dFlow << "\%" << endl;

    thRig.shift(20);
    dFlow = thRig.flow();
    outFile << "after shifting up more than rig max flow = " << dFlow << "\%" << endl;

    thRig.shutOff();
    isOn = thRig.isOn();
    outFile << "after shutting rig off, isOn = " << isOn << endl;

    isOn = thShuttle.isOn();
    dFlow = thShuttle.flow();

    outFile << "Shuttle flow at 4th gear is " << dFlow << "\%" << endl;

    outFile.close();
    return 0;
}
