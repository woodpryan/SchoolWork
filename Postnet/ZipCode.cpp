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

/*ZipCode class implementation file*/

#include "ZipCode.h"
#include <iostream>
#include <string>

using namespace std;

ZipCode::ZipCode(char digits[])
{
    initZipCode(digits);
}

void ZipCode::initZipCode(char digits[])
{
    int digitCount = 0;
    int countX     = 0;
    int countY     = 0;

    for(digitCount = 0; digitCount < 25; digitCount++)
    {
        m_barCode[countX][countY] = digits[digitCount];
        
        countX++;
        if(countX == 5)
        {
            countY++;
            countX = 0;
        }
    }
    calculateZip();
}

string ZipCode::getZipCode()
{
    return m_zipCode;
}

void ZipCode::printZipCode()
{
    cout << m_zipCode;
}

void ZipCode::calculateZip()
{
    int  postNetVal[] = {7, 4, 2, 1, 0};
    int  countX       = 0;
    int  countY       = 0;
    int  product      = 0;
    int  sumProducts  = 0;
    char chZip[5];

    for(countY = 0; countY < 5; countY++)
    {
        sumProducts = 0;
        for(countX = 0; countX < 5; countX++)
        {
            if(m_barCode[countX][countY] == '1')
            {
                product = postNetVal[countX];
            }
            else
                product = 0;

            sumProducts+= product;
        }//countX loop
        if(sumProducts == 11)
            sumProducts = 0;

        chZip[countY] = char(sumProducts + 48);//ASCII numbers begin at 48 with 0

    }//countY loop
    m_zipCode = string(chZip);
}

