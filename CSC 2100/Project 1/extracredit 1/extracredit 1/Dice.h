#ifndef Dice_H
#define Dice_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Dice
{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;
protected:
	int numSides;
};
#endif