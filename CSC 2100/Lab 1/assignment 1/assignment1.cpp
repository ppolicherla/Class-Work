//programmed by: Pavan Policherla
//assignment 1
//9/14/2015

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int age;
	double federalIncomeTax, stateTax, grossAmount, healthInsurance, netPay;
	string firstname, familyname;
	cout << fixed << showpoint << setprecision(2);
	
	
	cout << "How old are you?: ";
	cin >> age;
	cout << "What is your first and family name?(please use upper case letters): ";
	cin >> firstname;
	cin >> familyname;
	cout << "what is your gross pay?: ";
	cin >> grossAmount;
	
	if (age < 30)
		healthInsurance = 75.00;
	else if (age >= 30)
		healthInsurance = 100.00;

	federalIncomeTax = grossAmount*.15;
	stateTax = grossAmount*.035;

	netPay = grossAmount - federalIncomeTax - stateTax - healthInsurance;

	cout << firstname << ' ' << familyname << endl;
	cout << "Age: " << age << endl;
	cout << "Gross Amount: $" << grossAmount << endl;
	cout << "Federal Tax: $" << federalIncomeTax << endl;
	cout << "State Tax: $" << stateTax << endl;
	cout << "Health Insurance: $" << healthInsurance << endl;
	cout << "Net Pay: " << grossAmount << " - " << federalIncomeTax << " - " << stateTax << " - " << healthInsurance << " = " << netPay;

	return 0;

}