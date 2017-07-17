//Programmed By: Pavan Policherla
// extra credit 1
// 11/15//2015


#include <iostream>
#include "Dice.h"
#include "LoadedDice.h"
using namespace std;


int rollTwoDice(const Dice& die1, const Dice& die2);

int main()
{
	Dice dice1;//regurlar dice objects
	Dice dice2;
	LoadedDice ldice1(12);//loaded dice objects
	LoadedDice ldice2(12);
	//loop to test the regular dice
	for (int i = 0; i < 10; i++)
	{
		cout << rollTwoDice(dice1, dice2) << endl;
	}
	cout << endl;
	//loop to test the loaded dice
	for (int i = 0; i < 10; i++)
	{
		cout << rollTwoDice(ldice1, ldice2) << endl;
	}
}

// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}