/*  Assignment:     PostNet
    Author:         Ryan Wood
    Date Created:   January 15, 2018
    Requirements:   Calculate a Zip code using the PostNet system, which assigns
                    five zip code digits. Each digit contains five tall or short
                    bars (represented in data as 1 or 0) which map to 5 digits.
                    The digits are a fixed value (7, 4, 2, 1, and 0). For each
                    mapping, of 1 or 0, the value is multiplied. The five digits
                    are then added together to determine the zip code digit.
                    this is repeated for all of the five digits of the zip code.
*/

/*ZipCode class main test file. Reads the data file and prints the zipcode values*/

#include "ZipCode.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile("BarCode.txt");
ofstream outFile("ZipCodes.out");

void processZipCode(char barCode[])
{
    ZipCode zip(barCode);
    string  sZip = zip.getZipCode();
    
    outFile <<  sZip << endl;
}

void processFile()
{
    int  count = 0;
    int  index = 0;
    char barCode[25];
    char ch;

    while(inFile >> ch)
    {
        if(ch == '\n')
            continue;
        count++;
        if(count == 1)//first digit is not needed
            continue;
        if(count == 27)//last digit is not needed
        {
            count = 0;//each code is 26 chars long
            index = 0;
            processZipCode(barCode);
            continue;
        }
        barCode[index] = ch;
        index++;
    }
}

int main()
{
    /*char chZip[] = {'1', '0', '1', '0', '0',
                    '1', '0', '1', '0', '0',
                    '0', '1', '0', '1', '0',
                    '1', '1', '0', '0', '0',
                    '0', '1', '0', '0', '1',};
    ZipCode zip(chZip);
    zip.printZipCode();*/

    processFile();

    outFile.close();
    inFile.close();

    return 0;
}
