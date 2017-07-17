//programmed by: Pavan Policherla
//assignment 6
//10/11/2015

#include<iostream>
using namespace std;

int main()
{
	int num,x=0;
	int startingNumber = 1;
	int counter1=0, counter2=0;
	cout << "Please enter a number to be calculated: " << endl;

	cin >> num;

	int result = 0;
	for (int i = startingNumber; i <= num; i++)
	{
		result += i;
		counter1++;
	}

	cout << endl << "results of using the loop: " << result << " " << counter1 - 1 << endl;

	x=num + 1;
	counter2++;
	x = num*x;
	counter2++;
	x = x / 2;
	counter2++;
	cout << endl << "results using the formula: " << x << " " << counter2 << endl;

	return 0;
}