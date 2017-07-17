//programmed by: Pavan Policherla
// lab10 excersise 1
// 10/14/2015

#include <iostream>
#include <string>
using namespace std;

void upperCase(char p[], int stringLength);

int main()
{
	char *p;
	p = new char[20];
	int stringlenght;

	cout << "Please enter a  string: ";
	cin.getline(p, 20);
	cout << endl << endl;

	stringlenght = strlen(p);
	upperCase(p, stringlenght);

}

void upperCase(char p[], int stringLength)
{
	for (int i = 0; i < stringLength; i++)
	{
		p[i] = toupper(p[i]);
	}
	for (int i = 0; i < stringLength; i++)
	{
		cout << p[i];
	}
	cout << endl;
}