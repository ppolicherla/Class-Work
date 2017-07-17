#include<iostream>
#include "bookType.h"

using namespace std;

void bookType::setTitlePrice(string name, int cost)
{
	title = name;
	price = cost;
}

void bookType::showTitlePrice()
{
	cout << "The title is: " << title << endl;
	cout << "The price is: " << price << endl;
}

bookType::bookType()
{
	title = "null";
	price = 0;
}

bookType::bookType(string name, int cost)
{
	title = name;
	price = cost;
}