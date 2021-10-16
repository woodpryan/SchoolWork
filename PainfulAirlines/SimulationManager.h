/***
    @class      SimulationManager
    @author     Ryan Wood
    @date       September 22, 2020
    @details    This class manages the simulation of the Painful Airlines
                check-in lines. There are three lines of customers and there
                are three customer service representatives. The customers in
                the three different lines may be first class, business class,
                or economy class passengers. The reps are assigned to a particular
                class, but if they are not busy and a lower class passenger is waiting
                and not being helped, they may help. For each time tick, the
                status of the lines is checked, and new customers may be generated.
                Every 3 minutes an economy customer is generated. Every 15 minutes,
                a business class customer, and every 30 minutes, a first class
                customer. Once a customer is generated, it may be assigned to a
                rep that is not busy. However, once assigned to a rep, it takes
                a range of time for that representative to help the customer.
                If all the reps are busy when a customer is generated, the customer
                waits in the queue until a rep is available.
*/
#ifndef SIMULATION_MANAGER_H
#define SIMULATION_MANAGER_H

#include <string>
#include <iostream>
#include <queue>
#include <vector>

#include "Customer.h"
#include "CustomerServiceRep.h"

using namespace std;

/**TimeRange structure. time range between min and max*/
struct TimeRange
{
    int min;/**< Minimum time it takes to help a customer*/
    int max;/**< Maximum time it takes to help a customer*/
};

typedef queue<Customer> line;

class SimulationManager
{
private:

    static const int ECON_GEN_RATE        = 3;//rate at which economy customers generate
    static const int BUS_GEN_RATE         = 15;//rate at which business customers generate
    static const int FIRST_CLASS_GEN_RATE = 30;//rate at which first class customers generate

    TimeRange econAssistRate;//min and max time it takes to assist an economy customer
    TimeRange busAssistRate;//min and max time it takes to assist a business customer
    TimeRange firstClassAssistRate;//min and max time it takes to assist a first class customer

    vector<CustomerServiceRep> m_customerServiceReps;//list of customer service reps. There are three
    vector<Customer>           m_helpedCustomers;//list of all customers that have been helped
    vector<line>               m_lines;//list of customer lines. There are three

    int m_timeTarget;//the time at which the simulation will end
    int m_time;//the current simulation time

    int m_maxLineLengths[3];    //the maximum number of customers in each line during sim
    int m_lineLengthTotals[3]; //the accumulated total of line lengths for each second of sim

public:
    /** Function:   updateHelpStatus(CustomerType)
        @details    For the given customer type, this function retrieves the customer service
                    rep and, if they are busy helping a customer, determines how long they have
                    been helping the customer. If it is within the range of time it should take
                    to help, this function essentially flips a coin to determine whether they will
                    finish this customer at the current time tick. If it is determined its time
                    to finish via coin flip or because the max time it should take to help has
                    been reached, the rep finishes the customer they currently are helping,
                    which sets the amount of time it took for the customer to be helped.
                    The customer is added to the list of customers that have been helped.
        @param      the customer type as any of CustomerType
    */
    void updateHelpStatus(CustomerType custType);

    /** Function:   inRange(TimeRange, int)
        @details    this function determines if, for a given time range and amount of
                    time, whether the given time is within the range.
        @param      tr the time range as a TimeRange structure
        @param      simTime the amount of time that has passed
        @return     whether the time is within the range
    */
    int inRange(TimeRange tr, int simTime);

    /** Function:   getAssistRange(CustomerType)
        @details    for the given customer rep type, this function returns the range of time
                    it should take to help that customer. Different reps take a different
                    range of time to help a customer, regardless of the type of customer
                    they are actually helping.
        @param      custType the type of customer service representative
        @return     the range of time it takes the rep to help a customer
    */
    TimeRange getAssistRange(CustomerType custType);

    /** Function:   enqueueCustomer(CustomerType)
        @details    for the given customer type, this function generates a
                    customer at with the current sim time as its time that it
                    started waiting. Adds the customer to the appropriate line
                    according to its customer type
        @param      custType the type of customer to enqueue
    */
    void enqueueCustomer(CustomerType custType);

    /** Function:   helpCustomers(CustomerType)
        @details    this function helps customers of the given type. retrieves the next
                    customer in line from the appropriate line. If there is a representative
                    available to help the customer, pops the customer out of the line and
                    assigns it to the available rep. If the customer is of a type less than
                    first class and the rep that should help the customer is busy, the
                    rep for the next class type is assigned to the customer. For an economy
                    customer, if the economy rep is busy the business rep is checked, and if
                    they are busy, they first class rep is checked.
                    If all reps are currently busy, the customer continues to wait at least
                    until the next time this function is called.
        @param      custType the type of customer to help as any of CustomerType
    */
    void helpCustomers(CustomerType custType);

    /** Function:   toString(CustomerType)
        @details    for the given customer type enumeration value, this function
                    returns a string representation of that value. So, given
                    CustomerType.FIRS_CLASS, returns "First Class"
        @return     the customer type as a string
    */
    string toString(CustomerType custType);
    
    /** Function:   printLine(CustomerType)
        @details    this function prints information about the line that holds the given
                    customer type. Prints how many customers of this type are currently in
                    line and, if the customer service rep for this type is busy, what type
                    of customer they are helping at the moment. Also prints whether the
                    customer rep is not helping anyone.
                    If this function is alled at the end of sim time, it also prints
                    the average amount of time customers waited in the given line type,
                    the longest amount of time a customer of this type waited, and
                    the total number of customers of this type that were helped.
        @param      custType the type of customer
    */
    void printLine(CustomerType custType);

    /** Function:   SimulationManager(int)
        @details    this parameterized constructor takes the number of minutes
                    for which the simulation should run and initializes the
                    member variables of the simulation, adding three customer service
                    reps to the list of reps, setting the three time ranges for the
                    customer service reps, creating the three customer queues, and
                    initializing the maxLineLength and lineWaitTotal arrays to have
                    three zero values.
        @param      the number of minutes of sim tim
    */
    SimulationManager(int targetTime);

    /** Function:   ~SimulationManager()
        @details    destructor
    */
    ~SimulationManager();

    /** Functinon:  timeTick()
        @details    This function increments the simulation time by one. For each time
                    increment, customers may be generated depending on the generation
                    rates and they may be enqueued, customers may be assigned to representatives
                    if they are not all busy, customers that are currently being helped may be
                    finished depending on the amount of time they've been assigned and how
                    long it takes the reps to help a customer, customers may be removed from
                    the queue, or the simulation may finish. Calls the functions that handle
                    all these things, starting with the first class customer type and ending with
                    the economy customer type..
        @return     whether time remains in the simulation
    */
    bool timeTick();

    /** Function:   printLines()
        @details    this function prints information about the three lines. Simply calls
                    the printLine function for each of the different customer types.
                    Prints the information to a file in the execution directory called
                    Output.out.
    */
    void printLines();
};
#endif
