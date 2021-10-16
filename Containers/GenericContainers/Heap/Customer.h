#ifndef CUSTOMER_H
#define CUSTOMER_H

/*  Class:      Customer
    Purpose:    Specialized class created to
                demonstrate the priority heap
    Author:     Ryan Wood
    Created On: April 7, 2018
*/

class Customer
{
    public:
        int id;
        int priority;

        /*  Function:   operator >(Customer)
            Purpose:    returns whether the given customer has a
                        lower priority than the priority value
                        of this class instance
            Parameters: the customer to compare
            Return:     whether the customer has a lower priorty
        */
        bool operator >(Customer custA)
        {
            if(priority > custA.priority)
                return true;
            return false;
        }

        /*  Function:   operator <(Customer)
            Purpose:    determines whether the given customer has
                        a higher priority than the priority of
                        the current Customer class instance.
            Paramters:  the customer to compare
            Return:     whether the given customer has a higher priority
        */
        bool operator <(Customer custA)
        {
            if(priority < custA.priority)
                return true;
            return false;
        }
};

/*  Function:   operator <<(ostream&, Customer&)
    Purpose:    outputs the given customer's priority followed by
                a dash, followed by the customer's ID to the console
    Parameters: the output stream, the customer
    Return:     the output stream
*/
std::ostream& operator<<(std::ostream& out, Customer &cust)
{
    out << cust.priority << " - " << cust.id;
    return out;
}

/*  Function:   operator <<(ofstream&, Customer&)
    Purpose:    outputs the given customer's priority followed by
                a dash, followed by the customer's ID to the file stream
    Parameters: the output file stream, the customer
    Return:     the output file stream
*/
std::ofstream& operator<<(std::ofstream& out, Customer &cust)
{
    out << cust.priority << " - " << cust.id;
    return out;
}

#endif
