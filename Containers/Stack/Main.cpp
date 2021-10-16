#include "Stack.h"

using namespace std;
using namespace rimes;

int main()
{

    string stop  = "q";
    int    count = 0;

    Stack  myStack(10);
    string val;

    do
    {
        if(val.length() > 0)
        {
            myStack.push(val);
        }
        cout << "Enter a name: ";
        cin >> val;
    }while(val != stop);
    
    cout << "stop found" << endl;
    while(!myStack.empty())
    {
        val = myStack.top();
        myStack.pop();
        cout << count << ". " << val << endl;
        count++;
    }

    return 0;
}
