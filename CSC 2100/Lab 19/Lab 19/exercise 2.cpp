//Programmed By: Pavan Policherla
//exercise 2
// 11/19/2015

#include<iostream>
using namespace std;

int ackermann(int m, int n);

int main()
{
	int m, n;
	cout << "please enter two non-negative integers: ";
	cin >> m >> n;
	cout << endl << "HAVE FUN!!!!!";
	cout << ackermann(m, n) << endl;
}

int ackermann(int m, int n)
{
	if (m == 0) 
	{
		return n + 1;
	}
	else if (m>0 && n == 0) 
	{
		return ackermann(m - 1, 1);
	}
	else
	{
		return ackermann(m - 1, ackermann(m, n - 1));
	}
}