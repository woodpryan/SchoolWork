/***
    @class      Customer
    @author     Ryan Wood
    @date       September 22, 2020
    @details    This class holds information about a PainfulAirlines customer
                such as the time they entered their line, whether they are
                being helped, have been helped, and how much time they waited
                before they were helped
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

/** CustomerType
     * This is the CustomerType enumeration
     */
enum CustomerType
{
    ECONOMY     = 0,/**< Economy class */
    BUSINESS    = 1,/**< Business class*/
    FIRST_CLASS = 2 /**< first class   */
};

class Customer
{
private:
    CustomerType m_customerType; /*the type of customer as any of @ref CustomerType*/
    bool         m_isBeingHelped;/*whether the customer is being assisted by a CustomerServiceRep*/
    bool         m_isCaredFor;  /*Whether the customer has been waited on and is finished*/
    int          m_timeWaited;  /*the amount of time it took from creation to when the customer was finished*/
    int          m_timeCreated; /*the simulation time the customer was created*/


public:
    /** Function:   Customer()
        @details    This function initializes member variables to
                    their defaults. time created is set to 0.
    */
    Customer();

    /** Function:   Customer(int, CustomerType)
        @details    this parameterized constructor initializes the class
                    to have the given start time and customer type. Other
                    variables like whether the customer is being cared for
                    or if they've been helped are initialized to false
        @param      startWait The simulation time at which the customer was created
        @param      custType the customer type as any of @ref CustomerType
    */
    Customer(int startWait, CustomerType custType);

    /** Function:   Customer(const Customer&)
        @details    this is the copy constructor. Does a deep copy of the given customer's
                    member variables
        @param      otherCust the customer to copy
    */
    Customer(const Customer& otherCust);

    /** Function:   ~Customer()
        @details    this is the destructor for the customer
    */
    ~Customer();

    /** Function:   getTimeWaited() const
        @details    this function retrieves the amount of time the customer
                    waited after having been created before they were
                    helped and finished. If they have not been finished,
                    returns zero.
        @return     time waited
    */
    int getTimeWaited() const;

    /** Function:   getTimeCreated() const
        @details    This function returns the simulation time at which this
                    customer was created
        @return     the creation time for the customer
    */
    int getTimeCreated() const;

    /** Function:   isCaredFor() const
        @details    returns whether a customer service agent has finished
                    helping this customer
        @return     whether the customer has been helped
    */
    bool isCaredFor() const;

    /** Function:   isBeingHelped() const
        @details    Time passes between the time a customer is assigned to a
                    customer service rep and the time that the rep finishes
                    helping the customer. This function returns whether the
                    customer is being helped, but is has not been finished
        @return     whether the customer is being assisted now
    */
    bool isBeingHelped() const;

    /** Function:   startHelping()
        @details    this function sets the status of the customer as being helped.
    */
    void startHelping();

    /*  Function:   processCustomer(int)
        @details:   This function sets the customer as no longer waiting and no longer
                    being helped. The timeWaited can be retrived after this function
                    call. It is set to be the given simulation time minus the start time
        @param      simTime the current simulation time
    */
    void processCustomer(int simTime);

    /*  Function:   getCustomerType() const
        @details    this function retrieves the customer type
        @return     the customer type as any of @ref CustomerType
    */
    CustomerType getCustomerType() const;

    /*  Function:   =(Customer)
        @details    this function overloads the assignment operator, setting the
                    customer to be equal to the given customer
        @param      otherCust the other customer
    */
    void operator =(const Customer &otherCust);

};
#endif
