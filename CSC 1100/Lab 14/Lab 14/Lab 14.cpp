//Programmed by: Pavan Policherla
//Lab 14
//7/7/2015

#include<iostream>
using namespace std;

void printArray(const int x[], int sizeX);
int smallestIndex(const int x[], int sizeX);

int main()
{
	int x[] = { 2, 4, 3, 2, 4, 5 };
	int sizeX = 6;
	printArray(x, sizeX);
	cout << smallestIndex(x, sizeX)<<endl;
}

void printArray(const int x[], int sizeX)
{
	for (int i = 0; i < sizeX; i++)
		cout << x[i] << " ";
	cout << endl;
}

int smallestIndex(const int x[], int sizeX)
{
	int smallest=x[0], index=0;
	for (int i = 0; i < sizeX; i++)
	{
		if (x[i] <smallest)
		{
			smallest = x[i];
			index=i;
		}
	}
	return  index;
}