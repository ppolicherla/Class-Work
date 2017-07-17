//Programmed By: Pavan Policherla
// Assignemnt 9
// 11/3/2015

#include<iostream>
using namespace std;

int main()
{
	int array[10], temp=0, counter=0;
	cout << "Enter in a list of numbers to be sorted(press enter after each number): ";
	for (int i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10-i-1; j++)
		{
			counter++;
			if (array[j]>array[j + 1])
			{
				temp = array[j + 1];
				counter++;
				array[j + 1] = array[j];
				counter++;
				array[j] = temp;
				counter++;

			}
		}
	}
	cout << "Sorted List: ";
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
	cout << counter << " actions preformed" << endl;
}