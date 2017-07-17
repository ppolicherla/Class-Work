//Programmed by: Pavan Policherla
//Lab 7 question 2
//6/11/2015

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double meter, increment, feet;
	int conversion, i;

	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the starting meter value, increment value and number of iterations";
	cin >> meter >> conversion >> increment;
	cout << endl;

	i = 0;


	if (conversion > 10)
	{
		increment = 10;
	}
	while (i <= conversion)
	{
			feet = meter*3.281;
			cout << meter << '\t' << feet << endl;
			meter = meter + increment;
			i++;
	}
	cout << endl;
	return 0;
}