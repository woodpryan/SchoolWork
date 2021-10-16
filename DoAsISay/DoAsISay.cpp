/*  File:       DoAsISay
    Assignment: Object Oriented Programming, assignment 1, Do As I Say
    Date:       August 22, 2020
    Author:     Ryan Wood
    Purpose:    demonstrate some not-to-does
*/
#include <iostream>

using namespace std;

void  bufferOverrun(int*, int);
int   badPtr();
void  ptrPostIncrement();
int  &sumTwoIntegers(const int &, const int &);

//SampleObject class to demonstrat deadly destruction of class
class SampleObject
{
    private:
    int value;

    public:
    SampleObject()
    {
        value = 0;
        cout << "constructor called!\n";
    }

    ~SampleObject()
    {
        cout << "destructor called!\n";
    }

    void deadlyDestruct()
    {
        cout << (new SampleObject)->value << "\n";
    }
};

int main()
{
    int iTestA            = 0;
    int iTestB            = 0;
    int iTestReturn       = 0;
    int numItems          = 100;
    int dynamicArray[100] = {0};

    bufferOverrun(dynamicArray, numItems);
    cout << endl;

    badPtr();
    cout << endl;

    ptrPostIncrement();
    cout << endl;

    SampleObject *soDestruct = new SampleObject;
    cout << endl;

    iTestA = 10;
    iTestB = 24;

    iTestReturn = sumTwoIntegers(iTestA, iTestB);
    cout << "sumTwoIntegers return = " << iTestReturn << endl;
}

/*  Function:   bufferOverrun(int*, int)
    Purpose:    This function treats the given integer pointer as an array,
                and prints values from the given integer plus 100 more
                values. If the given array does not have enough elements,
                a buffer overrun will be the result.
    Parameters: an integer array, 
                the number of elements (also starting point for printing)
*/
void bufferOverrun(int *dynamicArray, int numberOfElements)
{
    int count = 0;

    cout << "bufferOverrun\n";
    count = numberOfElements;
    for(count = numberOfElements; count < (numberOfElements+100); count++)
    {
        cout << dynamicArray[count] << "\t";
        if(count%10 == 0)
            cout << endl;
    }
}

/*  Function:   badPtr()
    Purpose:    This function does some odd stuff with pointers
    Return:     0, spec says to return an integer, but does not
                specify what integer to return, so returns 0
*/
int badPtr()
{
    int *iPtr;
    int  iJust;
    int  iVal = 0;

    cout << "badPtr\n";

    iPtr = &iJust;
    iVal = *iPtr;

    cout << "iVal = " << iVal << endl;

    return 0;
}

/*  Function:   ptrPostIncrement()
    Purpose:    This function sets a pointer to the
                address of a variable and then increments
                the pointer.
*/
void ptrPostIncrement()
{
    int *ptrToInt = NULL;
    int  myInt    = 0;

    cout << "ptrPostIncrement\n";

    myInt    = 100;
    ptrToInt = &myInt;
    
    *ptrToInt++;
    cout << "ptrToInt = " << ptrToInt << endl;
    cout << "myInt = "    << myInt     << endl;
}

/*  Function:   sumTwoIntegers(int&, int&) int
    Purpose:    this function adds the two numbers together
                and returns the result
    Parameters: the first int, the second int
    Return:     the sum of the integers
*/
int &sumTwoIntegers(const int &a, const int &b)
{
    int iSum = 0;

    cout << "sumTwoIntegers!\n";
    iSum = a + b;

    return iSum;
}

