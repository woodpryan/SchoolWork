#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

class Foo
{
    public:
        Foo(tuple<int, float>)
        {
            cout << "Foo::Foo(tuple)" << endl;
        }

        template <typename... args>
        Foo(Args... args)
        {
            cout << "Foo:Foo(args...)" << endl;
        }
};

int main()
{
    
}
