//programmed by: Pavan Policherla
// assignment 2
// 9/8/2015

#include<iostream>
using namespace std;

int main()
{
	bool a , b , c ;
	
	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if ((a&&b) || (a&&c))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if ((a&&c) && (b&&!c))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if ((a || b) && !(b || c))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if ((a || (b&&c)) && (!a&&!b))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if (((b&&c) || (c&&a)) && (!(a || b) && c))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
	return 0;
}