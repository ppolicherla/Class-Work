// Programmed By: Pavan Policherla
// Lab 17
// 11/9/2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	double inches;
	double feet;
	double centimeters, meters;
	bool success = false;

	while (success != true)
	{
		try
		{
			cout << "Please enter the height in feet then inches: ";
			cin >> feet >> inches;

			if (feet < 0)
			{
				throw feet;
			}
			else if (inches < 0)
			{
				throw inches;
			}
			else if (feet < 0 && inches < 0)
			{
				throw feet, inches;
			}
			else if (cin.fail())
			{
				throw feet, inches;
			}
			else
			{
				centimeters = inches*2.54;
				meters = feet*0.3048;
				success = true;
			}
			cout << "Height is: " << meters << " meters and " << centimeters << " centimeters" << endl << endl;
		}
		catch (double)
		{
			cout << "Invalid value, please try again: " << endl << endl;
			cin.clear();   
			cin.ignore();
		}
	}
}