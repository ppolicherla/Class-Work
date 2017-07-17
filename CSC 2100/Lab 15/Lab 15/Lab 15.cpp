//Programmed By:Pavan Policherla
// Lab 15
// 11/2/2015

#include "newClock.h"
#include <iostream>
using namespace std;

int main()
{

	clockType clock1(12, 12, 12);
	clockType clock2(12, 12, 11);
	clockType clock3;

	clock3 = ++clock2;
	cout << clock3;
	cout << endl << endl;
	clock3 = clock1++;
	cout << clock3;
	cout << endl << endl;

	if (clock2 < clock1)
	{
		cout << "TRUE!!!!";
	}
	else
	{
		cout << "FALSE!!!";
	}
	cout << endl << endl;
	if (clock2 == clock3)
	{
		cout << "TRUE!!!!";
	}
	else
	{
		cout << "FALSE!!!";
	}
	cout << endl << endl;
}