//Programmed By: Pavan Policherla
//Assignment 12
//11/24/2015

#include<iostream>
using namespace std;

void pathFinder(int arr1[][10], int arr2[][10],  int m, int n, int i1, int i2, int counter);
int main()
{
	//for the last 9x9 matrix i hard coded it into the program but all others i did user input
	int arr1[10][10], arr2[10][10], row, col, counter=1;

	cout << "Enter rows and columns of initial matrix:  ";
	cin >> row >> col;

	if (row == col)
	{
		cout << "enter the 1st step matrix: ";
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> arr1[i][j];
			
			}
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr2[i][j] = arr1[i][j];
		}
	}


	int input;
	cout << "enter 1 for finding shortest distance from A to B: " << endl;
	cout << "enter 2 for finding shortest distance from B to A: " << endl;
	cout << "enter 3 for finding shortest distance from A to C: " << endl;
	cout << "enter 4 for finding shortest distance from B to C: " << endl;
	cout << "enter 5 for finding shortest distance from C to D: " << endl;
	cin >> input;
	switch (input)
	{
	case 1: pathFinder(arr1, arr2, row, col, 1, 0, counter);
		break;
	case 2: pathFinder(arr1, arr2, row, col, 0, 1, counter);
		break;
	case 3: pathFinder(arr1, arr2, row, col, 2, 0, counter);
		break;
	case 4: pathFinder(arr1, arr2, row, col, 2, 1, counter);
		break;
	case 5: pathFinder(arr1, arr2, row, col, 3, 2, counter);
		break;
	}
	
}

void pathFinder(int arr1[][10], int arr2[][10], int m, int n, int i1, int i2, int counter)
{
	if (arr1[i1][i2] > 0)
	{
		cout << counter << " steps" << endl;
	}
	else
	{
		counter++;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; k++)
				{
					arr1[i][j] = arr1[i][j] + (arr1[i][k] * arr2[k][j]);
				}
			}
		}
		pathFinder(arr1, arr2, m, n, i1, i2, counter);
	}
}

