//Programmed By: Pavan Policherla
//project 2 problem 2
//11/28/2015

#include <iostream>
#include "LargeIntegers.h"
using namespace std;

int main()
{
	//creation of variables and large integer objects
	int c;
	largeIntegers large1, large2, large3;
	//inputing the values for the large integer objects
	large1.input();
	large2.input();
	//performing the operations
	large1.output();
	cout << " + ";
	large2.output();
	large3 = large1 + large2;
	cout << " = ";
	large3.output();
	cout << endl<<endl;
	large1.output();
	cout << " - ";
	large2.output();
	large3 = large1 - large2;
	cout << " = ";
	large3.output();
	cout << endl<<endl;
	large1.output();
	cout << " * ";
	large2.output();
	large3 = large1 * large2;
	cout << " = ";
	large3.output();
	cout << endl<<endl;
	//comparing the two integers
	c = large1 == large2;
	large1.output();
	switch (c)
	{
	case -1:
		cout << " is less than ";
		break;
	case 0:
		cout << " is equal to ";
		break;
	case 1:
		cout << " is greater than ";
		break;
	}
	large2.output();
	cout << endl<<endl;

}