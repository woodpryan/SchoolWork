#include <iostream>

using namespace std;

void printLetters(char startChar, char endChar)
{
    /*base case: the letters are equal
                    print the start char*/
    /*Case 2: start char is less than end char
      print from start char to end char, then back to start char*/
    /*Case 3: end char is greater than start char
       print from end char to start char*/

    if(startChar < endChar)
    {
        cout << endChar;
        printLetters(startChar, endChar-1);
        cout << endl;
        cout << startChar;
        printLetters(startChar+1, endChar);
    }
    else if(startChar > endChar)
    {
        cout << startChar;
        printLetters(startChar+1, endChar);
        cout << endl;
        cout << endChar;
        printLetters(startChar, endChar-1);
    }
    else if(startChar == endChar)
    {
        //cout << startChar;
        return;
    }
}

int main()
{
    printLetters('A', 'H');
    return 0;
}
