#include "Queue.h"

using namespace std;
using namespace rimes;

int main()
{

    string stop  = "q";
    int    count = 0;

    Queue myQ(10);
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
