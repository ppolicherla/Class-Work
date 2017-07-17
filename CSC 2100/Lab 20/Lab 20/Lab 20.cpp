//Programmed By: Pavan Policherla
// Lab 20
// 11/23/2015

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int binarySearch(vector<string> name, string value, int middle);

int main()	
{

	vector<string> names{ "Ali", "Ben", "Carol", "Ella", "Faria", "Loren", "Paul" };

	string search;
	cout << "Please enter a name to search for(names must be capitalized for the first letter): ";
	cin >> search;

	if (binarySearch(names, search, 3) == 0)
	{
		cout << "Found it!!!!!" << endl;
	}

	

	return 0;
}

int binarySearch(vector<string> name, string value, int middle)
{
	int out = value.compare(name[middle]);
	if (out == 0)
	{
		return out;
		cout << "Found!!!";
	}
	else if (out<0)
	{
		return binarySearch(name, value,  middle - 1);
	}
	else if(out>0)
	{
		return binarySearch(name, value, middle + 1);
	}
	return 1;
}