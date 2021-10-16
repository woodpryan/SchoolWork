#include <iostream>

#include "Customer.h"

Customer::Customer()
{
    m_timeCreated   = 0;
    m_timeWaited    = 0;
    m_customerType  = ECONOMY;
    m_isCaredFor    = false;
    m_isBeingHelped = false;
}

Customer::Customer(int simTime, CustomerType custType)
{
    m_timeCreated  = simTime;
    m_timeWaited   = 0;
    m_customerType = custType;
}

Customer::Customer(const Customer& otherCust)
{
    m_timeCreated  = otherCust.getTimeCreated();
    m_timeWaited   = otherCust.getTimeWaited();
    m_customerType = otherCust.getCustomerType();
}

Customer::~Customer()
{
}

int Customer::getTimeWaited() const
{
	return m_timeWaited;
}

bool Customer::isCaredFor() const
{
	return m_isCaredFor;
}

bool Customer::isBeingHelped() const
{
    return m_isBeingHelped;
}

void Customer::startHelping()
{
    m_isBeingHelped = true;
}

void Customer::processCustomer(int simTime)
{
    m_timeWaited    = simTime - m_timeCreated;
    m_isCaredFor    = true;
    m_isBeingHelped = false;
}

CustomerType Customer::getCustomerType() const
{
    return m_customerType;
}

int Customer::getTimeCreated() const
{
    return m_timeCreated;
}

void Customer::operator =(const Customer &otherCust)
{
    m_timeCreated  = otherCust.getTimeCreated();
    m_timeWaited   = otherCust.getTimeWaited();
    m_customerType = otherCust.getCustomerType();
}
