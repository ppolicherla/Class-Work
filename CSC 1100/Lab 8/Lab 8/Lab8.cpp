//Programmed by: Pavan Policherla
//Lab 8
//6/16/2015
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int num, units;
	cout << "Enter a number to be reversed";
	cin >> num;
	cout << endl;
	do
	{
		units = num % 10;
		num /= 10;
		cout << units;
	} 
	while (num != 0);	

	return 0;
}