//programmed by: Pavan Policherla
// lab 4 assignment 2
// 9/23/2015

#include<iostream>
#include<cmath>
using namespace std;
void smallestIndex(int array[15]);
int main()
{
	int array[15] = { 56, 34, 67, 54, 23, 87, 66, 92, 15, 32, 55, 54, 88, 22, 30 };//size of 15

	smallestIndex(array);
}

void smallestIndex(int array[15])
{
	int temp=array[0];
	int index = 0;
	for (int i = 0; i < 15; i++)
	{
		if (array[i] < temp)
		{
			index = i;
			temp = array[i];
		}
	}

	cout << "the smallest index is: " << index << endl;

}