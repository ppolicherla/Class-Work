//Programmed by: Pavan Policherla
//Lab 02 exercise 2
//9/16/2015

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double hypotenuse, leg1, leg2;
	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter the length of the hypotenuse: ";
		cin >> hypotenuse;
		cout << endl << "Please enter the length of leg 1: ";
		cin >> leg1;
		cout << endl << "Please enter the length of leg2: ";
		cin >> leg2;

		if ((pow(hypotenuse, 2)) == (pow(leg1, 2) + pow(leg2, 2)))
			cout << "This is a right triangle!" << endl;
		else
			cout << "not quite what a right triangle is." << endl;

	}
}