#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

const int numDigits = 6;
string    randomDigits;

/*  Function:   getRandomInt()
    Purpose:    returns a random integer between MIN and MAX
    Parameters: min, max
    Return:     a random number
 */
int getRandomInt(int MIN, int MAX)
{
    int random = 0;

    random = (rand() % (MAX - MIN + 1)) + MIN;

    return random;
}

/*  Function:   generateRandomDigits()
    Purpose:    this function generates a number of random digits
                between 0 and 9. The number of digits generated
                is determined by the global constant numDigits.
                Each digit is placed in a string.
    Return:     a string of random digits
*/
string generateRandomDigits()
{
    int    randomNum = 0;
    int    count     = 0;
    string sRand;
    
    //increment count from 0 to the value of numDigits
    for(count = 0; count < numDigits; count++)
    {
        //generate a random digit between 0 and 9 and add to string
        randomNum = getRandomInt(0, 9);
        sRand     = sRand + to_string(randomNum);
    }

    return sRand;
}

/*  Function:   guess()
    Purpose:    generates strings of random numbers until it
                generates one that is equal to the global
                variable in which the original generated
                string of digits is stored. Counts the
                number of times it generates a guess before
                it finds a correct string of digits
    Return:     the number of guesses
*/
long long guess()
{
    long long numGuesses = 1;
    string    numbers    = "";

    //while the numbers string is not equal to
    //the random string, generate a random string to guess with
    while(numbers.compare(randomDigits) != 0)
    {
        numbers = generateRandomDigits();
        numGuesses++;//increment guess count
    }
    return numGuesses;
}

int main()
{
    unsigned  t          = time(NULL);
    long long numGuesses = 0;

    srand(t);

    //generate the string of digits to guess and get the number of
    //guesses it takes to regenerate it randomly
    randomDigits = generateRandomDigits();
    numGuesses   = guess();

    cout << "The randomg digits = " << randomDigits << endl;
    cout << "It took " << numGuesses << " guesses to find it." << endl;

    return 0;
}
