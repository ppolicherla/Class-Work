//programmed by: Pavan Policherla
//assignment 7
// 10/15/2015

#include<iostream>
#include<string>
using namespace std;

int main()
{
	char *p;
	p = new char[20];
	cout << "Enter a string of commands: ";
	cin.getline(p, 20);
	string state = "cat";

	for (int i = 0; i < strlen(p); i++)
	{
		switch (p[i])
		{
		case'A':
			if (state == "cat")
				cout << "Meow" << endl;
			else if (state == "noise")
				cout << "Boing" << endl;
			else if (state == "food")
				cout << "Lemons" << endl;
			break;
		case 'B':
			if (state == "cat")
				cout << "Ignore" << endl;
			else if (state == "noise")
				cout << "Thud" << endl;
			else if (state == "food")
				cout << "Cinnamon" << endl;
			break;
		case '1':
			if (state == "cat")
				state="food";
			else if (state == "noise")
				state = "cat";
			else if (state == "food")
				state = "noise";
			break;
		case '2':
			if (state == "cat")
				state="noise";
			else if (state == "noise")
				state="food";
			else if (state == "food")
				state="cat";
			break;
		default:
			cout << "THOMAS!!!!!!!!!!" << endl;

		}
	}


}