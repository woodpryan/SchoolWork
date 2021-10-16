#include <iostream>
#include <fstream>
#include <time.h>

#include "SimulationManager.h"
#include "CustomerServiceRep.h"

using namespace std;

ofstream outFile("Output.out");

SimulationManager::SimulationManager(int timeTarget)
{
    unsigned t = 0;
    line     econ;
    line     bus;
    line     firstClass;

    t = time(NULL);
    srand(t);

    m_timeTarget = timeTarget;
    m_time       = 0;

    econAssistRate.min       = 5;
    econAssistRate.max       = 10;
    busAssistRate.min        = 6;
    busAssistRate.max        = 12;
    firstClassAssistRate.min = 5;
    firstClassAssistRate.max = 20;

    m_customerServiceReps.push_back(CustomerServiceRep());
    m_customerServiceReps.push_back(CustomerServiceRep());
    m_customerServiceReps.push_back(CustomerServiceRep());

    m_lines.push_back(econ);
    m_lines.push_back(bus);
    m_lines.push_back(firstClass);

    for(int index = 0; index < 3; index++)
    {
        m_lineLengthTotals[index] = 0;
        m_maxLineLengths[index] = 0;
    }
}

SimulationManager::~SimulationManager()
{
    outFile.close();
}

/*  Function:   getRandomInt()
    Purpose:    returns a random integer between MIN and MAX
    Parameters: min, max
    Return:     a random number
 */
int getRandomInt(int MIN, int MAX)
{
    int      random = 0;
    
    random = (rand() % (MAX - MIN + 1)) + MIN;

    return random;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

void SimulationManager::enqueueCustomer(CustomerType custType)
{
    Customer genericCustomer(m_time, custType);

    m_lines[custType].push(genericCustomer);
}

TimeRange SimulationManager::getAssistRange(CustomerType custType)
{
    switch(custType)
    {
        case ECONOMY:
            return econAssistRate;
            break;
        case BUSINESS:
            return busAssistRate;
            break;
        case FIRST_CLASS:
            return firstClassAssistRate;
            break;
        default:
            break;
    }
}

int SimulationManager::inRange(TimeRange tr, int assistTime)
{
    if(tr.min > assistTime)//under range
        return -1;
    else if(tr.max <= assistTime)//need to finish serving this customer
        return 1;
    else
        return 0;//could finish serving, but don't have to
}

void SimulationManager::updateHelpStatus(CustomerType custType)
{
    int       iRange        = 0;
    bool      doHelp        = false;
    int       assistTime    = m_customerServiceReps[custType].getTimeSpentOnCustomer(m_time);
    TimeRange assistRange   = getAssistRange(custType);
    Customer  cust;

    iRange = inRange(assistRange, assistTime);

    if(iRange == 0)
        doHelp = getRandomInt(0, 1);
    else if(iRange == 1)
        doHelp = true;

    if(doHelp)
    {
        if(m_customerServiceReps[custType].isBusy())
        {
            m_customerServiceReps[custType].finishCustomer(m_time);
            cust = m_customerServiceReps[custType].getCustomer();

            m_helpedCustomers.push_back(cust);
        }
    }
    m_maxLineLengths[custType] = max(m_maxLineLengths[custType], m_lines[custType].size());
    m_lineLengthTotals[custType] += m_lines[custType].size();
}

void SimulationManager::helpCustomers(CustomerType custType)
{
    Customer     cust;
    CustomerType backup;
    bool         helped = false;
    
    if(!m_lines[custType].empty())
    {
        cust   = m_lines[custType].front();
        backup = custType;
        helped = cust.isBeingHelped();
        while(backup <= FIRST_CLASS && !helped)
        {
            if(!m_customerServiceReps[backup].isBusy())
            {
                m_customerServiceReps[backup].startHelping(m_time, cust);
                helped = true;
                m_lines[custType].pop();
            }
            else
                backup = static_cast<CustomerType> (backup + 1);
        }
    }
}

bool SimulationManager::timeTick()
{
    m_time++;
    if(m_time >= m_timeTarget)
        return false;

    //determine whether we need to generate customers
    if(m_time % ECON_GEN_RATE == 0)
    {
        enqueueCustomer(ECONOMY);
    }

    if(m_time % BUS_GEN_RATE == 0)
    {
        enqueueCustomer(BUSINESS);
    }

    if(m_time % FIRST_CLASS_GEN_RATE == 0)
    {
        enqueueCustomer(FIRST_CLASS);
    }

    if(m_time % 10 == 0)
        printLines();

    updateHelpStatus(FIRST_CLASS);
    updateHelpStatus(BUSINESS);
    updateHelpStatus(ECONOMY);

    //determine whether we need to help customers
    //if the first class line is not empty, give the first customer to a rep
    helpCustomers(FIRST_CLASS);
    helpCustomers(BUSINESS);
    helpCustomers(ECONOMY);

    return true;
}

string SimulationManager::toString(CustomerType custType)
{
    switch(custType)
    {
        case FIRST_CLASS:
            return "First Class";
            break;
        case BUSINESS:
            return "Business Class";
            break;
        case ECONOMY:
            return "Economy Class";
            break;
    }
}

void SimulationManager::printLine(CustomerType custType)
{
    int      numHelped    = 0;
    int      numCustomers = 0;
    int      timeWaited   = 0;
    int      index        = 0;
    double   avg          = 0.0;
    Customer cust;

    outFile << "Time " << m_time << ":\t";
    outFile << "Line: " << toString(custType) << endl;
    


    numCustomers = m_lines[custType].size();
    outFile << numCustomers << " customers in line." << endl;

    if(m_customerServiceReps[custType].isBusy())
    {
        cust = m_customerServiceReps[custType].getCustomer();
        outFile << "Customer service rep is helping a "
             << toString(cust.getCustomerType()) << " customer " << endl;
    }
    else
        outFile << "Customer service rep is not helping anyone." << endl;

    if(m_time < m_timeTarget)
        return;

    for(index = 0; index < m_helpedCustomers.size(); index++)
    {
        cust = m_helpedCustomers[index];
        if(cust.getCustomerType() == custType)
        {
            timeWaited+= cust.getTimeWaited();
            numHelped++;
        }
    }
    if(numHelped > 0)
        avg = timeWaited / numHelped;
    outFile << "Number helped: " << numHelped << endl;
    outFile << "Average wait time: " << avg << endl;

    outFile << "Average Line length: " << (m_lineLengthTotals[custType] / m_time) << endl;
    outFile << "Max Line length: " << m_maxLineLengths[custType] << endl << endl;
    
}

void SimulationManager::printLines()
{
    printLine(FIRST_CLASS);
    outFile << endl;
    printLine(BUSINESS);
    outFile << endl;
    printLine(ECONOMY);
    outFile << endl;
}

