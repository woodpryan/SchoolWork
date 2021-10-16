#include "Customer.h"
#include "CustomerServiceRep.h"
#include "SimulationManager.h"

#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    SimulationManager simManager(720);

    while(simManager.timeTick())
    {
        count++;
    }
    simManager.printLines();
    return 0;
}
