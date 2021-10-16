/*  Assignment:     General List Program
    Author:         Ryan Wood
    Created On:     1/28/2018
    Requirements:   Defined in Document "General List Program"
                    provided by Dr. Rimes
*/
/*List Main file provided by Dr. Rimes. Modified to output to file*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"

using namespace std;
using namespace rimes;

int main()
{
    ofstream outFile("TestList.out");
  	List a,b;  int endit;

	for (int i=1;i<=20;i++)
	   a.insertAfter(i*2);
	outFile << "List a : " << endl;
    outFile << "  "  << a << endl;
	outFile << "Number of elements in a - " << a.size() << endl;

	for (int i=1;i<=20;i++)
	   b.insertBefore(i*2);
	outFile << "List b : " << endl;
    outFile << "  "  <<  b << endl;
	outFile << "Number of elements in b - " << b.size() << endl;

	if ( a == b )
	    outFile << "List a & b are equal" << endl;
	  else
	    outFile << "List a & b are Not equal" << endl;

	a.first();
	b.first();
	outFile << "First elmenet in list a & b: " << a.getElement() << ", "
				       << b.getElement() << endl;
	a.last();
	b.last();
	outFile << "Last elmenet in list a & b: " << a.getElement() << ", "
				     << b.getElement() << endl;
					 
	outFile << endl << endl << " Start of new stuff" << endl;

	b.erase();
	if ( a == b )
	    outFile << "List a & b are equal" << endl;
	  else
	    outFile << "List a & b are Not equal" << endl;

	a.setPos(10);
	for(int i = 1; i < 8; i++)
	{
	   a.erase();
	   b.replace(i);
	   b.next();
	}

	outFile << "Modified Object 'a' " << endl;
    outFile << "List a: " << a << endl;
	outFile << "Modified Object 'b' " << endl;
    outFile << "List b: " << b << endl;

	List c(b);
	outFile << "Copy Constructor c(b)" << endl;
    outFile << "List b : " << b << endl;
    outFile << "List c : " << c << endl;

	if ( c == b )
	    outFile << "List c & b are equal" << endl;
	  else
	    outFile << "List c & b are Not equal" << endl;


	List e;
	e = c;
	outFile << "Object 'c' assigned to Object 'e':" << endl;
    outFile << "List c : " << c << endl;
    outFile << "List e : " << e << endl;

    List d;
	d=a;
	d.first();
	endit = d.size()/2;
	for (int i=1; i<=endit; i++)
	{
		d.next();
		d.erase();
	}
	outFile << "Results after some erases: Object d  " << endl;
    outFile << "List d : " << d << endl;

	d.first();
	endit = d.size();
	for ( int i = 1; i < endit; d.next(), i++)
	{
		d.insertBefore(d.getElement()*5);
		d.next();
	}
	outFile << "Results after some Replaces on d " << endl;
    outFile << "List d : " << d << endl;

	a.first();
	endit = a.size();
	for ( int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos()+a.getElement());
		a.next();
	}
	outFile << "Results after some weird stuff on list a" << endl;
    outFile << "List a : " << a << endl;

    List alist(b);
    alist.clear();
    for (int i=1;i<=10;i++)
	   alist.insertAfter(i);
	alist.first();
	outFile << "New List alist with positions above: " << endl;
    for (int i=1;i<=10;i++) {
		outFile << setw(5) << alist.getPos();
		alist.next();
	}
	outFile << endl;
	alist.first();
	for (int i=1;i<=10;i++) {
		outFile << setw(5) << alist.getElement();
		alist.next();
	}
	outFile << endl;
	
	outFile << endl << "  check out boundary conditions" << endl;
	List sq;
	outFile << "number of elements in empty sq list = " << sq.size() << endl;
	sq.first();
	sq.erase();
	sq.setPos(5);
	outFile << "empty sq values " << sq << endl;
	sq.insertBefore(777);
	outFile << "sq values " << sq << endl;
	sq.next(); sq.next();
	outFile << "sq.getElement() = " << sq.getElement() << endl;
	outFile << "sq list = " << sq << endl;

    outFile.close();
	return 0;
  }
