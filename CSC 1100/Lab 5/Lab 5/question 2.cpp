//Programmed by: Pavan Policherla
//Lab 3 question 1
//6/4/2015

#include<iostream>

using namespace std;

int main()
{
	int num1, num2, num3;
	cout << "Please enter three numbers: "; 
	cin >> num1 >> num2 >> num3;

	if (num3 <= num1)
	{
		cout << endl << endl << num3 << ' ' << num1 << ' ' << num2 << endl;
	}
	else if (num1 <= num3 && num3 <= num2)
	{
		cout << endl << endl << num1 << ' ' << num2 << ' ' << num3 << endl;
	}
	else cout << endl << endl << num1 << ' ' << num2 << ' ' << num3 << endl;
}