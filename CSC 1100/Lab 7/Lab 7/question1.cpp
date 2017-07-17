//Programmed by: Pavan Policherla
//lab 7 question 1
//6/11/2015

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int weight, year, weightClass;
	double registrationFee;

	cout << fixed << showpoint << setprecision(2);
	cout << "Please enter the car's model year and the weight ";
	cin >> year >> weight;
	cout << endl;
	if (year <= 1990)
	{
		if (weight <= 2700)
		{
			weightClass = 1;
			registrationFee = 26.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
		else if (weight >= 2700 && weight <= 3800)
		{
			weightClass = 2;
			registrationFee = 35.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
		else if (weight >= 3800)
		{
			weightClass = 3;
			registrationFee = 56.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
	}
	else if (year >= 1991 && year <= 1999)
	{
		if (weight <= 2700)
		{
			weightClass = 4;
			registrationFee = 35.00;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
		else if (weight >= 2700 && weight <= 3800)
		{
			weightClass = 5;
			registrationFee = 45.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
		else if (weight >= 3800)
		{
			weightClass = 6;
			registrationFee = 62.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
	}
	else if (year >= 2000)
	{
		if (weight <= 3500)
		{
			weightClass = 7;
			registrationFee = 49.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
		else if (weight >= 3500)
		{
			weightClass = 8;
			registrationFee = 62.50;
			cout << "The weight class of the car is " << weightClass << " and the registration fee is " << registrationFee << endl;
		}
	}
	else
	{
		cout << "The car cannot be insured, We are sorry for the insufficiencies of out service. Good bye!" << endl;
	}
	return 0;
}