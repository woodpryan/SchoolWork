#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    Vector is an array that allows us to add items without worrying about
    the size of the list. push_back allows us to add an item
*/
int main(int argc, char *argv[])
{
    vector<string> projects;
    for(int i = 1; i < argc; ++i)
    {
        projects.push_back(argv[i]);
        cout << projects[i-1] << endl;
    }
    return 0;
}
