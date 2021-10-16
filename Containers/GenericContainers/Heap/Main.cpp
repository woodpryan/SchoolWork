/*  Assignment:     Heap Program
    Author:         Ryan Wood
    Created On:     April 1, 2018
    Requirements:   Create a priority heap class and
                    test it using the program specified
                    in the document Heap Program handed out
                    in class March 27, 2018
*/
/*********Main file****************/

#include <iostream>
#include <fstream>

#include "../List/List.h"
#include "Heap.h"
#include "Customer.h"

using namespace std;
const int CAPACITY = 105;

Heap<Customer, CAPACITY> customerHeap;

ifstream inFile("HeapPriortyNbrs.dat");
ofstream outFile("HeapOutput.out");

/*  Function:   readRequests(int)
    Purpose:    reads as many items from the input file
                as specified by the given integer value,
                reading the id followed by a dash, followed
                by the priority and adding customer class
                instances to the heap based on the data
                found in the file. -1 may be passed to simply
                read all data items that remain in the file
    Parameters: the number of customer reauests to read
                or -1 if all data items should be read
*/
void readRequests(int numRequests)
{
    int       count = 0;
    Customer *cust  = NULL;
    char      dash  = '-';

    cust = new Customer;

    while((count < numRequests  || numRequests == -1) && !inFile.eof())
    {
        inFile >> cust->id;
        inFile >> dash;
        inFile >> cust->priority;

        customerHeap.push(*cust);
        count++;
    }
    delete cust;
}

/*  Function:   popCustomers(int, int)
    Purpose:    prints the number of customers from the heap as given
                as the first integer argument up to the number of items
                given as the second argument, which is the number of items
                to pop. Pops items off the heap, printing them as it goes
                until the given numToPop has been reached. Ceases to print
                to the console or file once the given numToPrint integer
                value has been reached
    Parameters: the number of values to print,
                the number of values to pop from the stack
*/
void popCustomers(int numToPrint, int numToPop)
{
    Customer *cust    = NULL;
    int       count   = 0;
    int       printed = 0;

    cust = new Customer;
    while((count < numToPop && customerHeap.size() > 0) || 
         (numToPop == -1 && customerHeap.size() > 0))
    {
        *cust = customerHeap.top();
        customerHeap.pop();
        if(count < numToPrint)
        {
            printed++;
            if(printed > 1)
            {
                outFile << ", " << *cust;
                cout    << ", " << *cust;
            }
            else
            {
                outFile  << *cust;
                cout     << *cust;
            }
            if(printed %10 == 0)
            {
                outFile << endl;
                cout    << endl;

                printed = 0;
            }
        }
        count++;
    }
    outFile << endl;
    cout    << endl;
}

int main()
{
    if(!inFile)
    {
        cout << "Bad input file name." << endl;
        return -1;
    }
    readRequests(100);
    popCustomers(20, 50);

    readRequests(50);
    popCustomers(30, 50);

    readRequests(-1);
    popCustomers(40, -1);

    return 0;
}
