/*  Assignment:     Queue and Stack Program
    Author:         Ryan Wood
    Created On:     February 18, 2018
    Requirements:   Decode the "CodedMsg.txt" file that was encoded using
                    the algorithm described in document QueueInterLeaveDecode.doc,
                    posted to Blackboard by Dr. Rimes on February 15, 2018.
*/

/*Stack, Queue, List Main file*/

//include my containers
#include "../Containers/GenericContainers/List/List.h"
#include "../Containers/GenericContainers/Stack/Stack.h"
#include "../Containers/GenericContainers/Queue/Queue.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile("CodedMsg.txt");
ofstream outFile("DecodeMsg.txt");

const size_t CAPACITY = 200;

typedef string et;
Stack<et, CAPACITY> stack;
Queue<et, CAPACITY> que;

/*  Function:   transferHalfQueueToStack()
    Purpose:    transfers the front half of the que to the stack
*/
void transferHalfQueueToStack()
{
    int half   = 0;
    int count  = 0;
    int qSize  = 0;
    et  strVal = "";

    qSize = que.size();
    half = qSize/2;

    for(count = 0; count < half; count++)
    {
        strVal = que.top();
        que.pop();
        stack.push(strVal);
    }
}

/*  Function:   shiftHalfFrontQueueBack()
    Purpose:    shifts the front half of the queue
                to the back
*/
void shiftHalfFrontQueueBack()
{
    string strVal  = "";
    int    queSize = 0;
    int    half    = 0;
    int    count   = 0;

    queSize = que.size();
    half = queSize/2;
    
    for(count = 0; count < half; count++)
    {
        strVal = que.top();
        que.pop();
        que.push(strVal);
    }
}

/*  Function:   interLeave()
    Purpose:    this function loops through all elements of the
                queue. Uses the stack as a temporary storage location
                so it can flip the value of each successive element
                in the queue.
*/
void interLeave()
{
    et  strVal = "";
    int count  = 0;
    int qSize  = 0;

    qSize = que.size();
    for(count = 0; count < qSize; count++)
    {
        strVal = que.top();
        que.pop();
        
        if(count %2 == 0)
        {
            stack.push(strVal);
        }
        else
        {
            que.push(strVal);
            if(!stack.empty())
            {
                strVal = stack.top();
                stack.pop();
                que.push(strVal);
            }
        }
    }
}

/*  Function:   pushHalfAlternateQueueToStack()
    Purpose:    This function steps through half of the elements
                of the queue and pushes every other element to the
                stack. The elements it does not push to the stack,
                it pushes to the beginning of the queue (itself).
                In either case, pops the value off the top. Only
                goes through half of the queue.
*/
void pushHalfAlternatQueueToStack()
{
    int queueSize = 0;
    int count     = 0;
    int half      = 0;
    et  strVal    = "";

    queueSize = que.size();
    half = queueSize/2;

    for(count = 0; count < half; count++)
    {
        strVal = que.top();
        if(count %2 == 0)
            stack.push(strVal);
        else
            que.push(strVal);

        que.pop();
    }
}

/*  Function:   pushAlternateQueueToStack()
    Purpose:    this function steps through all the elements
                of the queue and pushes every other element
                to the stack. The elements it does not push
                to the stack, it pushes to the back of the
                queue (itself). In both instances, pops the
                value off the top, ensuring we get no duplicates
*/
void pushAlternatQueueToStack()
{
    int queuSize = 0;
    int count    = 0;
    et  strVal   = "";

    queuSize = que.size();

    for(count = 0; count < queuSize; count++)
    {
        strVal = que.top();
        if(count %2 == 0)
            stack.push(strVal);
        else
            que.push(strVal);

        que.pop();
    }
}

/*  Function:   transferStackToQueue()
    Purpose:    this function transfers the contents of the stack
                beginning with top to the back of the queue
*/
void transferStackToQueue()
{
    et  strVal    = "";
    int count     = 0;

    while(!stack.empty())
    {
        strVal = stack.top();
        que.push(strVal);
        stack.pop();
    }
}

/*  Function:   writeDecodedToFile()
    Purpose:    this function outputs the final queue values
                to the file DecodedMsg.txt as the decoded message
*/
void writeDecodedToFile()
{
    et strVal = "";

    while(!que.empty())
    {
        strVal = que.top();
        que.pop();
        outFile << strVal << " ";
    }
}

/*  Function:   loadFileToQueue()
    Purpose:    loads the contents of the CodedMsg.txt file
                into the Queue container class
*/
void loadFileToQueue()
{
    et strVal;

    while(inFile >> strVal)
    {
        if(!que.full())
        {
            que.push(strVal);
        }
        else
        {
            cout << "We're gonna need a bigger boat!" << endl;
            return;
        }
    }
}

int main()
{
    if(!inFile)
    {
        cout << "Could not load the input file." << endl;
        return -1;
    }

    loadFileToQueue();

    interLeave();
    pushAlternatQueueToStack();
    transferStackToQueue();
    shiftHalfFrontQueueBack();
    transferHalfQueueToStack();
    transferStackToQueue();
    shiftHalfFrontQueueBack();

    que.print();
    cout << endl;
    cout << "Number of elements in Queue = " << que.size() << endl;

    writeDecodedToFile();

    inFile.close();
    outFile.close();

    return 0;
}
