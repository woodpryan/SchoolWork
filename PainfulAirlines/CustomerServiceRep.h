/***
    @class      CustomerServiceRep
    @author     Ryan Wood
    @date       September 22, 2020
    @details    This class is a Customer Service Representative for Painful Airlines.
                The CustomerServiceRep has function definitions that allow it to
                start helping customers or finish helping a customer at a given time.
*/

#ifndef CUSTOMER_SERVICE_REP
#define CUSTOMER_SERVICE_REP

#include <iostream>

#include "Customer.h"

using namespace std;

class CustomerServiceRep
{
private:
    Customer m_customer;/**The customer that this rep is currently helping*/
    int      m_helpStart;/**the time at which the rep started helping the customer*/
    bool     m_isHelping;/**whether the rep is helping a customer currently*/

public:

    /*  Function:   CustomerServiceRep(int, Customer)
        @details    Parameterized constructor takes the current simulation time and
                    a Customer. After this function is called, the rep is helping the
                    given customer and started at the given time.
        @param      simTime the current simulation time, which is when the rep starts helping
        @param      cust the customer that the rep is helping
    */
    CustomerServiceRep(int simTime, Customer cust);
    
    /** Function:   CustomerServiceRep()
        @details    default constructor. The rep is not helping anyone after this
                    constructor is called. Initializes member variables to defaults
    */
    CustomerServiceRep();

    /** Function:   CustomerServiceRep(const CustomerServiceRep &)
        @details    Copy constructor. Sets the rep to have the same member variables as
                    the given rep
    */
    CustomerServiceRep(const CustomerServiceRep &otherRep);

    /** Function:   ~CustomerServiceRep();
        @details    destructor
    */
    ~CustomerServiceRep();

    /** Function:   isBusy() const
        @details    this function returns whether the rep is currently helping a customer
        @return     whether the rep is currently helping a customer
    */
    bool isBusy() const;
    
    /** Function:   getTimeSpentOnCustomer(int) const
        @details    this function determines how much simulation time has elapsed
                    since the rep began helping its current customer until the
                    given simulation time
        @param      simTime the current simulation time
        @return     the amount of time the rep has been helping its current customer
    */
    int getTimeSpentOnCustomer(int simTime) const;

    /** Function:   startHelping(int, Customer)
        @details    this function assigns the given customer to the rep at the given
                    simulation time. Sets whether the rep is busy to true
        @param      simTime the current simulation time
        @param      cust the customer to help
    */
    void startHelping(int simTime, Customer cust);

    /** Function:   finishCustomer(int)
        @details    this function sets the rep to be not helping
                    a customer anymore, and the customer it is
                    currently helping is passed the given simulation
                    time as the time at which they were helped.
        @param      simTime the current simulation time
    */
    void finishCustomer(int simTime);

    /** Function:   getCustomer() const
        @details    this function returns the customer the rep is currently helping
        @return     the customer the rep is helping
    */
    Customer getCustomer() const;

    /** Function:   getHelpStart()
        @details    this function returns the time at which the rep started helping
                    its current customer
        @return     the time the rep started on the current customer
    */
    int getHelpStart() const;
};

#endif
