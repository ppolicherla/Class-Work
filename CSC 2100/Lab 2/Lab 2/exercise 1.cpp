//Programmed by: Pavan Policherla
//Lab 02 exercise 2
//9/16/2015

#include<iostream>
using namespace std;

int main()
{
	double num1, num2, num3;
	double output;

	cout << "Please enter 3 numbers: ";
	cin >> num1 >> num2 >> num3;
	if ((num1 == 0) || (num2 == 0) || (num3 == 0))
	{
		cout << "All numbers must be non zero" << endl;
	}

	if ((num1 > num2) && (num3 > 0))
	{
		output = num1 / num2;
	}
	else if ((num1 < num2) || (num3 < 0))
	{
		output = num2 / num1;
	}
	else
	{
		output = num1*num2*num3;
	}

	cout << output << endl;

	
}