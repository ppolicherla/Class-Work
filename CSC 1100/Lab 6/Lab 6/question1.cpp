//Programmed by: Pavan Policherla
//Lab 6 question 1
//6/9/2015

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double num1, num2;
	char ch;
	cout << "Please enter the degrees in either Fahrenheit or Celcius ";
	cin >> num1 >> ch;
	cout << endl;
	if (ch == 'F' || ch == 'f')
	{
		num2 = (5.0 / 9.0)*(num1 - 32.0);
		cout << "The temperature in Celcius is " << num2 << " C" << endl;
	}
	else if(ch == 'C' || ch == 'c')
	{
		num2 = (num1*(9.0/5.0)+32.0);
		cout << "The temperature in Fahrenheit is " << num2 << " F" << endl;
	}
	else
	{
		cout << "The temperature inputed is neither in Fahrenheit or Celcius" << endl << endl;
	}
	return 0;
}