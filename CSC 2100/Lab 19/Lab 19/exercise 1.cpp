//Programmed By: Pavan Policherla
// Lab 19 exercise 1
// 11/19/2015

#include<iostream>
using namespace std;

int power(int x, int y);

int main()
{
	int x, y;
	cout << "Please enter the 1st integer: ";
	cin >> x;
	cout << "Please enter the 2nd integer: ";
	cin >> y;
	if (x == 0&&y==0)
	{
		cout << "Both numbers are invalid, re-enter: ";
		cin >> x >> y;
	}
	else if (x == 0)
	{
		cout << "x is invalid, re-enter: ";
		cin >> x;
	}
	else if (y == 0)
	{
		cout << "y is invalid, re-enter: ";
		cin >> y;
	}
	else
	{
		cout << "answer: " << power(x, y) << endl;
	}
}

int power(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	if (y % 2 == 0) 
	{
		if (y == 2)
		{
			return x * x;
		}
		else
		{

			return power(power(x, y / 2), 2);
		}
	}
	else
	{
		return x * power(x, y - 1);
	}
}