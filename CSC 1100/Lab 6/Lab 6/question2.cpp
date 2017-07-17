//Programmed by: Pavan Policherla
//Lab 6 question 2
// 6/9/2015

#include <iostream>
using namespace std;

int main()
{
	double num1, num2;
	char ch;
	cout << "Please enter the degrees in either Fahrenheit or Celcius ";
	cin >> num1 >> ch;
	cout << endl;
	switch (ch)
	{
	case 'f':
		num2 = (5.0 / 9.0)*(num1 - 32.0);
		cout << "The temperature in Celcius is " << num2 << " C" << endl;
		break;
	case 'F':
		num2 = (5.0 / 9.0)*(num1 - 32.0);
		cout << "The temperature in Celcius is " << num2 << " C" << endl;
		break;
	case 'c':
		num2 = (num1*(9.0 / 5.0) + 32.0);
		cout << "The temperature in Fahrenheit is " << num2 << " F" << endl;
		break;
	case 'C':
		num2 = (num1*(9.0 / 5.0) + 32.0);
		cout << "The temperature in Fahrenheit is " << num2 << " F" << endl;
		break;
	default:
		cout << "The temperature inputed is neither in Fahrenheit or Celcius" << endl << endl;
	}
	return 0;
}