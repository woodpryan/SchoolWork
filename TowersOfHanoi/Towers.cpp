#include <iostream>
#include <ctime>

using namespace std;

long long moves = 0;

/*  Function:   move(int, char, char, char)
    Purpose:    Recursively solves the Towers of Hanoi puzzle using
                the given number of disks and utilizing the given
                source, destination and spare pegs
    Parameters: the number of disks left to move, the source peg,
                the destination peg, the peg to use as a spare
    Return:     the number of moves it took to complete the puzzle
*/
long long move(int n, char source, char destination, char spare)
{
    long long numMoves = 0;
    if(n == 1)
    {
        cout << "Move the top disk from " << source
             << " to " << destination << endl;
        return 1;
    }
    else
    {
        numMoves += move(n-1, source, spare,       destination);
        numMoves += move(1,   source, destination, spare);
        numMoves += move(n-1, spare,  destination, source);
    }
    return numMoves;
}

void printLetters(char startChar, char endChar)
{
    if(startChar >= endChar)
    {
        cout << startChar << endl;
        return;
    }
    else
    {
        cout << startChar;
        printLetters(startChar+1, endChar);
        cout << endChar;
    }
}

int main()
{
    time_t start = 0;
    time_t hTime = 0;
    time_t end   = 0;
    time_t diff  = 0;

    start = time(0);
    moves = move(50, 'A', 'B', 'C');
    end   = time(0);
    hTime = moves;

    cout << moves << endl;

    diff = end - start;

    cout << "It took this computer " << diff << " seconds to solve the puzzle" << endl;
    cout << "If one move was made per second, it would take a human " 
         << hTime/(525600*60) << " years " << endl;

    //printLetters('A', 'D');
    return 0;
}
