#include<iostream>
#include "Header.h"
using namespace std;

	testClass::testClass()
	{
		x = 0;
		y = 0;
	}
	//Default constructor
	//Initializes the private member variables to 0
	testClass::testClass(int a, int b)
	{
		x = a;
		y = b;
	}
	//Constructors with parameters
	//initializes the private member variables to the values
	//specified by the parameters
	//Postcondition:x=a;y=b;
	int testClass::sum()
	{
		int total;
		total = x + y;
		return total;

	}
	//Returns the sum of the private member variables
	void testClass::print() const
	{
		cout << "A is: " << x << endl;
		cout << "B is: " << y << endl;
	}
	//Prints the values of the private member variables


