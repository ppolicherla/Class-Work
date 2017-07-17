//programmed by: Pavan Policherla
// lab18
// 11/16/2015

#include<iostream>
using namespace std;
int sum(int arr[], int size);

int main()
{
	int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "I am running.";
	cout << sum(num, 10);
}

int sum(int arr[], int size)
{
	if (size == 0)
	{
		return 0; // terminating point
	}
	else
	{
		return arr[size - 1] + sum(arr, size - 1);

	}
}