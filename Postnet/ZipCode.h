#ifndef ZIP_CODE_H
#define ZIP_CODE_H

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
/*ZipCode class header file*/

#include <string>

using namespace std;

class ZipCode
{
    public:
        /*  Function:   ZipCode(char[])
            Purpose:    initialzes and calculates a zip code
                        based on the given bar code character array
            Parameters: an array of 25 characters, all of which are 0 or 1
            Return:     a zip code matching the bar code
        */
        ZipCode(char[]);

        /*  Function:   initZipCode(char[])
            Purpose:    initialzes and calculates a zip code
                        based on the given bar code character array
            Parameters: an array of 25 characters, all of which are 0 or 1
        */
        void initZipCode(char[]);

        /*  Function:   getZipCode()
            Purpose:    retrieves the string representation of the zip code
            Return:     the zip code
        */
        string getZipCode();

        /*  Function:   printZipCode()
            Purpose:    prints the zip code to the console
        */
        void printZipCode();
    private:
        
        /*  Function:   calculateZip()
            Purpose:    This function uses the two-dimensional bar code
                        character array that was created by initZipCode
                        to calculate five zip code digits based on the
                        PostNet system described in the Requirements
                        of this program. Populates the m_zipCode string
            PostCond:   m_zipCode is populated with a value
        */
        void calculateZip();

        char   m_barCode[5][5];
        string m_zipCode;
};

#endif
