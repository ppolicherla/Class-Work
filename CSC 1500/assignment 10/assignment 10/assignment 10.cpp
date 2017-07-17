//Programmed By: Pavan Policherla
// Assignment 10
// 11/3/2015

#include<iostream>
using namespace std;
int pivotSort( int arr[], int a, int z);
void bubblesort( int array[], int size);
int main()
{
	int pivotCounter;
	int array[10]= { 10,9,8,7,6,5,4,3,2,1 };

	bubblesort(array, 10);


	pivotCounter=pivotSort(array, 0, 9);


	cout << endl << "Pivot actions: " << pivotCounter << endl;


	return 0;
}

int pivotSort( int arr[], int a, int z)
{
	int pivotSpot = arr[a];
	int pivotNum = a;
	int pivotCounter = 0;
	for (int j = a; j <= z; j++)
	{
		if (arr[j] < pivotSpot)
		{
			pivotCounter = pivotCounter + 1;
			swap(arr[pivotNum + 1], arr[j]);
			pivotCounter = pivotCounter + 3;
			swap(arr[pivotNum], arr[pivotNum + 1]);
			pivotCounter = pivotCounter + 3;
			pivotNum++;
		}
	}

	if (a < z)
	{
		pivotSort(arr, a, pivotNum - 1);
		pivotSort(arr, pivotNum + 1, z);

	}

	return pivotCounter;

}


void bubblesort( int array[], int size)
{
	int temparr[10], temp = 0, counter = 0;
	for (int k = 0; k < 10; k++)
	{
		temparr[k] = array[k];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			counter++;
			if (temparr[j]>temparr[j + 1])
			{
				temp = temparr[j + 1];
				counter++;
				temparr[j + 1] = temparr[j];
				counter++;
				temparr[j] = temp;
				counter++;

			}
		}
	}
	cout << "Sorted List: ";
	for (int i = 0; i < 10; i++)
	{
		cout << temparr[i] << ", ";
	}
	cout << endl << endl;
	cout << counter << " Bubble actions: " << endl;
}