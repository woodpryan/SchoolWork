#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string firstName;
    string lastName;
    string address;
};

//lambda attempt.
auto h = [](Person person)
{
    return std::hash<string>(person.firstName) ^ hash<string>(person.lastName) ^ hash<string>(person.address);
};

int main()
{
    Person p;
    p.firstName = "Ryan";
    p.lastName = "Wood";
    p.address = "blah";
    h(p);
    return 0;
}
