//Programmed By: Pavan Policherla
//Lab 16
//7/14/2015

#include<iostream>
#include<string>

using namespace std;

void reverse(char m[], char n[]);

int main()
{
	char m[80];
	char n[80];

	cout << "please enter a character list to be reversed: ";
	cin.getline(m, 80);
	reverse(m, n);
	
	return 0;
}

void reverse(char m[], char n[])
{
	int length=0;
	char counter;

	for (int i = 0; i < 80; i++)
	{
		counter = m[i];
		if (m[i] == '\0')
		{
			length = i;
			i = 80;
		}
	}
	for (int j = 0; j <length; j++)
	{
		int counter = length - 1 - j;
		n[j] = m[counter];
		cout << n[j];
	}
	cout << endl;

}