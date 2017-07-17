//Programmed By: Pavan Policherla
//lab13 question 1
//7/2/2015
#include<iostream>
using namespace std;


int main()
{
	int sum=0, average;
	int grade[8];
	cout << "Please enter 8 integer numbers into the array: ";
	for (int i = 0; i < 8; i++)
	{
		cin >> grade[i];
	}
	cout << endl;
	for (int j = 0; j < 8; j++)
	{
		sum = sum + grade[j];
	}
	cout << "The grades are: ";
	for (int i = 0; i < 8; i++)
	{
		cout << grade[i]<<" ";
	}
	average = sum / 8;
	cout << endl;
	cout << "And the average is: " << average << endl;
    

}