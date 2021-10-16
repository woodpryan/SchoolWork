/*  File:       SimpleProgram.cpp
    Purpose:    This file demonstrates the use of arrays, input files and output files
                as well as pointers. It is a solution to the first programming assignment
                in Software Engineering
    Author:     Ryan Wood
    Created On: May 22, 2021
*/

#include <iostream>
#include <fstream>

using namespace std;

ofstream outFile("arry.out");
ifstream inFile("Numbers.dat");

/*  Function:   getSum(int*, int)
    Purpose:    determines the sum of all elements in
                the given array of the given size
    Parameters: the array, the size of the array
    Return:     the sum of all elements
*/
int getSum(int *arry, int size)
{
    int *iter;
    int  sum   = 0;
    int  count = 0;

    iter = arry;
    while(count < size)
    {
        sum += *iter;
        iter++;
        count++;
    }

    return sum;
}

/*  Function:   getAverage(int*, int)
    Purpose:    determines the average of all the
                values in the given array of the given size
    Parameters: the array, the size of the array
    Return:     the average of the values
*/
double getAverage(int *arry, int size)
{
    int    sum     = 0;
    double average = 0.0;

    sum = getSum(arry, size);
    average = (double) sum/size;

    return average;
}

/*  Function:       readArrayValues(int*, int)
    Purpose:        reads the values from the file and stores
                    them all in the given array having the given size
    Parameters:     the array, the size
    Postcondition:  The array is filled with values
 */
void readArrayValues(int *iArray, int iSize)
{
    int  num  = 0;
    int *iter = NULL;

    iter = iArray;

    while(inFile >> num)
    {
        *iter = num;
        iter++;
    }
}

/*  Function:   countNumbers() int
    Purpsoe:    This function counts the number of lines in
                the input file and returns the result
    Return:     the number of lines
*/
int countNumbers()
{
    int count = 0;
    int num   = 0;

    while(inFile >> num)
    {
        count++;
    }

    inFile.clear();
    inFile.seekg(0, inFile.beg);

    return count;
}

int main()
{
    int    *arry  = NULL;
    int     iSize = 0;
    double  avg   = 0.0;//the average of the values

    iSize = countNumbers();
    arry  = new int[iSize];

    readArrayValues(arry, iSize);
    avg = getAverage(arry, iSize);
    
    outFile << fixed;
    outFile << setprecision(2);
    outFile << avg;
    outFile.close();
    inFile.close();
    return 0;
}
