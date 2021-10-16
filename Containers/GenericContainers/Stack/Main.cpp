#include "Stack.h"

using namespace std;

int main()
{

    string stop  = "q";
    int    count = 0;

    Stack<string, 10>  myStack;
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
