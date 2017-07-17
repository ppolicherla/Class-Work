// Programed by: Pavan Policherla
//Lab 03 question 1
//05/28/2015

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double pound;
	cout << fixed << showpoint << setprecision(2);
	cout << "What is the weight in pounds? ";
	cin >> pound;
	cout << endl;

	double kilo = pound / 2.2;

	cout << "the weight in kilograms is: " << kilo << endl;
	cout << "and the weight in pounds is " << pound << endl;
	
	return 0;
}