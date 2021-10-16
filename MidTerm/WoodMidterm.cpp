#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream inFile("InputFile.txt");//open the read file

/*  Function:   getValue() double
    Purpose:    this function reads fifteen lines from a file,
                assuming the values contained are valid integers.
                The function adds the first fourteen of those integers
                into a sum, then devides them by the fiteeenth number,
                returning the result.
    Return:     the sum of the 14 numbers divided by the fifteenth
*/
double getValue()
{
    int    linesRead  = 0;
    double sumOfLines = 0.0;
    double num        = 0.0;
    double dValue     = 0.0;

    while(inFile >> num && linesRead++ < 15)
    {
        sumOfLines+= num;
    }
    //debug lines. Uncomment to see sumOfLines and last num
    /*cout << "Sum Of Lines = " << sumOfLines << endl;
    cout << "Last num = " << num << endl;*/
    dValue = sumOfLines/num;

    return dValue;
}

int main()
{
    double dValue = 0.0;
    
    dValue = getValue();

    //set the output to 2 decimal places
    cout << fixed;
    cout << setprecision(2);

    //output the result
    cout << "the value is " << dValue << endl;

    inFile.close();

    return 0;
}
