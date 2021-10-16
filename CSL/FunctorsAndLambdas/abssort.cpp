//
// File:	abssort.cpp
// Author:	Adam.Lewis@athens.edu
// Purpose:
// Simple example using a lambda expression
//

#include <algorithm>
#include <cmath>
using namespace std;

void abssort(double *x, unsigned n)
{
  sort(x,
	    x+n,
	    // Third parameter is some sort of funciton objec
	    // We'll do a lambda expression
	    [](double a, double b)
	    {
	      return(abs(a) < abs(b));
	    }
       );
}

int main()
{
  double doubleArray[] = {3.4, 2.1, 6.7, 1.1, 0.0015};
  abssort(doubleArray, 5);
  return 1;
}
