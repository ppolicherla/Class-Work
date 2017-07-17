//Programmed by: Pavan Policherla
//Lab 10
//6/23/2015

#include<iostream>
#include<cmath>
using namespace std;

double calculateCharges(double hours)
{
	double charge;
	if (hours <= 3.0)
		charge = 2.00;
	if (hours > 3.0)
	{
		charge = 2.0 + 0.50*ceil(hours-3.0);
		if (charge > 10)
			return 10;
	}
	return charge;
}

int main()
{
	int i;
	double hours, totalHours, totalCharge;
	totalHours = 0;
	totalCharge = 0;
	cout << "Please enter the hours that the car was parked for: ";
	for (i = 1; i <= 3; i++)
	{
		cin >> hours;
		cout << endl;
		cout << i << '\t' << hours << '\t' << calculateCharges(hours);
		totalHours = totalHours + hours;
		totalCharge = totalCharge + calculateCharges(hours);
	}
	cout << endl << "TOTAL" << '\t' << totalHours << '\t' << totalCharge << endl;
	return 0;

}