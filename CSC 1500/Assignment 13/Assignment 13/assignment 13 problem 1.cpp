//Programmed By: Pavan Policherla
// Assignment 13
// 12/8/2015

#include <iostream>
#include <cmath>
#include <string>
using namespace std;



int main()
{

	cout << "Truth table: " << endl;

	for (int a = 1; a >= 0; a--)
	{
		for (int b = 1; b >= 0; b--)
		{
			for (int c = 1; c >= 0; c--)
			{
				if (!(!(a^c) && (b||a)))
					cout << a << '\t' << b << '\t' << c << '\t' << "True" << endl;
				else
					cout << a << '\t' << b << '\t' << c << '\t' << "False" << endl;
			}
		}
	}
}

