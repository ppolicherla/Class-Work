//Programmed By: Pavan Policherla
//Lab12
//6/30/2015

#include<iostream>
#include<iomanip>
using namespace std;

void change(int amount, int& hundreds, int& fifties, int& twenties, int& tens, int& fives, int& ones)
{
	hundreds = amount / 100;
	amount = amount % 100;
	fifties = amount / 50;
	amount = amount % 50;
	twenties = amount / 20;
	amount = amount % 20;
	tens = amount / 10;
	amount = amount % 10;
	fives = amount / 5;
	amount = amount % 5;
	ones = amount;
}

int main()
{
	int amount;
	int hundreds, fifties, twenties, tens, fives, ones;
	cout << "please enter a dollar amount: ";
	cin >> amount;
	cout << endl;
	change(amount, hundreds, fifties, twenties, tens, fives, ones);
	cout << "There are " << hundreds << " hundreds" << endl;
	cout << "There are " << fifties << " fifties" << endl;
	cout << "There are " << twenties << " twenties" << endl;
	cout << "There are " << tens << " tens" << endl;
	cout << "There are " << fives << " fives" << endl;
	cout << "There are " << ones << " ones" << endl;
	return 0;
}