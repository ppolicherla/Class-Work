// Programmed By: Pavan Policherla
// Lab 16
// 11/4/2015

#include<iostream>
#include<string>
#include"LineType.h"
#include "myArray.h"
using namespace std;


int main()
{
	lineType line1(1, 2, 3);
	lineType line2(1, 2, 3);

	if (+line1)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	cout << endl << endl;
	if (-line2)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	cout << endl << endl;
	if (line1==line2)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}

	cout << endl << endl;
	if (line1||line2)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
	cout << endl << endl;
	myArray<int> bo();
	myArray<string> blah(2, 7);
	myArray<string> string(blah);
	myArray<int> doub(5);
	myArray<int> doub2(doub);
	doub2 = bo;
	string = doub2;
	string[](7);
	doub2 == doub;
	string != blah;
	~bo();
	~blah();
	~string();
	~doub();
	~doub2();
	
}