//programmed by:Pavan Policherla
//Lab 7
//10/5/2015

#include "bookType.h"
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
	string name[10];
	int cost[10];
	bookType store[10];
	ifstream infile;
	infile.open ("input.txt");

	for (int i = 0; i < 10; i++)
	{
		infile >> name[i];
		infile >> cost[i];
	}


	for (int i = 0; i < 10; i++)
	{
		store[i].setTitlePrice(name[i], cost[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		store[i].showTitlePrice();
		cout << endl;
	}

}