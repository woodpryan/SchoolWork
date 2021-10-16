#include <iostream>

using namespace std;

int power(int x, int n)
{
    if(n == 1)
        return x;
    else
        return x * power(x, n-1);
}

template<typename type>
type sum(type a, type b)
{
    return a + b;
}

template<typename type>
void tSwap(type &a, type &b)
{
    type tmp;

    tmp = a;
    a   = b;
    b   = tmp;
}

int main()
{
    cout << power(4, 4) << endl;

    cout << sum(2, 5) << endl;

    cout << sum(4.2, 1.4) << endl;

    int a = 5;
    int b = 10;

    tSwap(a, b);

    cout << "a = " << a << " b = " << b << endl;

    return 0;
}
