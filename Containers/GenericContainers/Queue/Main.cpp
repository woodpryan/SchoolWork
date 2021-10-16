#include "Queue.h"

using namespace std;

int main()
{
    string stop  = "q";
    int    count = 0;

    Queue<string, 10> myQ;
    string val;

    do
    {
        if(val.length() > 0)
        {
            myQ.push(val);
        }
        cout << "Enter a name: ";
        cin >> val;
    }while(val != stop);
    
    while(!myQ.empty())
    {
        val = myQ.top();
        myQ.pop();
        cout << count << ". " << val << endl;
        count++;
    }

    return 0;
}
