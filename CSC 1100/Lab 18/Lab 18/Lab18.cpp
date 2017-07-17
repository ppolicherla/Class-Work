//Programmed by: Pavan Policherla
//Lab18
//7/23/2015

#include<iostream>
#include<string>
using namespace std;

struct fruitType
{
	string name;
	string color;
	int fat;
	int sugar;
	int carbs;
};

int main()
{
	fruitType fruit;
	cout << "please enter the info for the fruit: " << endl;
	cout << "Name: "; 
	cin >> fruit.name;
	cout << endl << "Color: ";
	cin >> fruit.color;
	cout << endl << "Amount of Fat: ";
	cin >> fruit.fat;
	cout << endl << "Amount of Sugar: ";
	cin >> fruit.sugar;
	cout << endl << "Amount of Carbohydrates: ";
	cin >> fruit.carbs;
	cout << endl;
	cout << "Name: " << fruit.name << endl;
	cout << "Color: " << fruit.color << endl;
	cout << "Amount of Fat: " << fruit.fat << endl;
	cout << "Amount of Sugar: " << fruit.sugar << endl;
	cout << "Amount of Carbohydrates: " << fruit.carbs << endl;
}