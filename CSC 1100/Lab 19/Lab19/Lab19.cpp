//Programmed By: Pavan Policherla
//Lab 19
//7/28/2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int array_size;
	char q;
	cout << "please enter the length of the string: ";
	cin >> array_size;
	//cin.get(q);
	cout << endl;
	array_size = array_size + 1;
	char *p;
	p = new char[array_size];
	cout << "Please input a string of the length: ";
	cin.getline(p, array_size);

	for (int i = 0; i < array_size - 1; i++)
	{
		p[i] = toupper(p[i]);
		cout << p[i];
	}
	cout << endl;

	delete []p;

	return 0;
}