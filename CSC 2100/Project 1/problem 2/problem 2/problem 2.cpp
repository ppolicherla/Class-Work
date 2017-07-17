// Programmed By: Pavan Policherla
// problem 2
// 11/15/2015

#include<iostream>
#include<string>
#include "DynamicStringArray.h"
using namespace std;

int main()
{
	//creating dynamic array object
	DynamicStringArray<string> people;

	//adding elements to the array
	people.addEntry("Pavan");
	people.addEntry("Justin");
	people.addEntry("Monday");
	people.addEntry("Sandy");
	people.addEntry("Armando");

	//output of the list
	cout << "List: " << endl;
	for (int i = 0; i < people.getSize(); i++)
	{
		cout << people.getEntry(i) << endl;
	}
	cout << endl;

	//testing the delete entry function
	people.addEntry("ANNA");
	cout << "List with added name: " << endl;
	for (int i = 0; i < people.getSize(); i++)
	{
		cout << people.getEntry(i) << endl;
	}
	cout << endl;

	people.deleteEntry("ANNA");
	cout << "List after deleting entry: " << endl;
	for (int i = 0; i < people.getSize(); i++)
	{
		cout << people.getEntry(i) << endl;
	}
	cout << endl;

	//testing the copy constructor
	DynamicStringArray<string> peeps(people);
	cout << "Copied names: " << endl;
	for (int i = 0; i < peeps.getSize(); i++)
	{
		cout << peeps.getEntry(i) << endl;
	}
	cout << endl;

	//Testing the operator
	DynamicStringArray<string> crowd = peeps;
	peeps.deleteEntry("Justin");
	cout << "Crowd: " << endl;
	for (int i = 0; i < crowd.getSize(); i++)
	{
		cout << crowd.getEntry(i) << endl;
	}
	cout << endl;

	//creating an int dynamic array
	DynamicStringArray<int> inte;

	inte.addEntry(5);
	inte.addEntry(10);
	inte.addEntry(4);
	inte.addEntry(6);

	for (int i = 0; i < inte.getSize(); i++)
	{
		cout << inte.getEntry(i) << endl;
	}
	cout << endl;

	inte.deleteEntry(10);
	inte.addEntry(11);

	DynamicStringArray<int> num(inte);

	DynamicStringArray<int> num1 = num;

}