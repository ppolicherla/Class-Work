//Programmed by: Pavan Policherla
//Lab 4
//6/2/2015

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int d1, d2;
	double averageDailyBalance, netBalance, payment, interest;

	cout << "what is the net balance of the account? ";
	cin >> netBalance;
	cout << endl;

	cout << "what is the payment made on the balance? ";
	cin >> payment;
	cout << endl;

	cout << "how many days are in the billing cycle? ";
	cin >> d1;
	cout << endl;

	cout << "how many days before the billing cycle is the payment made? ";
	cin >> d2;
	cout << endl;

	averageDailyBalance = (netBalance*d1 - payment*d2) / d1;

	interest = averageDailyBalance*0.0152;

	cout << fixed << showpoint << setprecision(2);
	cout << endl << endl << "the interest for this account is " << interest << endl;

	return 0;

}