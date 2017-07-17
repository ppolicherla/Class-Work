//Programmed By: Pavan Policherla
//Lab 13 question2
//7/2/2015

#include<iostream>
using namespace std;

int main()
{
	int numbers[] = { 0, 0, 1, 5, 15, -300, -2, 0, -9, 400, 25, -6, -18, 500, 65, 10, -10, 11, -11, 900 };
	int positive[20];
	int negative[20];
	int p = 0;
	int n = 0;


	for (int i = 0; i < 20; i++)
	{
		if (numbers[i] >= 0)
		{
			
			positive[p]=numbers[i];
			p++;
		}
		else
		{
			negative[n]=numbers[i];
			n++;
		}
	}

	cout << "The original array is: ";
	for (int i = 0; i < 20; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "the positive and zero values are: ";
	for (int i = 0; i<p; i++)
	{
		cout << positive[i] << " ";
	}
	cout << endl;


	cout << "And the negative values are: ";
	for (int j = 0; j < n; j++)
	{
		cout << negative[j] << " ";
	}
	cout << endl;

	return 0;
}