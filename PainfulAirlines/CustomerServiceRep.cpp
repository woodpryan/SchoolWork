#include "CustomerServiceRep.h"

    //Customer m_customer;
    //int      m_helpStart;

CustomerServiceRep::CustomerServiceRep(int simTime, Customer cust)
{
    m_helpStart = simTime;
    m_customer  = cust;
    if(m_helpStart > 0)
        m_isHelping = true;
}
    
CustomerServiceRep::CustomerServiceRep(const CustomerServiceRep &otherRep)
{
    m_customer  = otherRep.getCustomer();
    m_helpStart = otherRep.getHelpStart();
    m_isHelping = otherRep.isBusy();
}

CustomerServiceRep::CustomerServiceRep()
{
    m_helpStart = 0;
    m_isHelping = false;
}

CustomerServiceRep::~CustomerServiceRep()
{
}

bool CustomerServiceRep::isBusy() const
{
    return m_isHelping;
}
    
int CustomerServiceRep::getTimeSpentOnCustomer(int simTime) const
{
    return simTime - m_helpStart;
}

void CustomerServiceRep::startHelping(int simTime, Customer cust)
{
    cust.startHelping();
    m_helpStart = simTime;
    m_customer  = cust;
    m_isHelping = true;
}

void CustomerServiceRep::finishCustomer(int simTime)
{
    m_isHelping = false;
    m_helpStart = 0;
    m_customer.processCustomer(simTime);
}

Customer CustomerServiceRep::getCustomer() const
{
    return m_customer;
}

int CustomerServiceRep::getHelpStart() const
{
    return m_helpStart;
}

