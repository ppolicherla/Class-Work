#include"LoadedDice.h"
using namespace std;
//default constructor that mirrors the constructor in the dice class
LoadedDice::LoadedDice()
{
	numSides = 6;
	srand(time(NULL));
}
// constructor that mirrors the constructor in the dice class
LoadedDice::LoadedDice(int numsides)
{
	numSides = numsides;
	srand(time(NULL));
}
//overloaded roll dice function that will more than 50% of the time return the total number of sides of the dice
int LoadedDice::rollDice() const
{
	if ((rand() % 100 + 1) > 50)//generates and random number and checks if it is greater than 50, if not it returns the largest number.
	{
		return (rand() % numSides) + 1;
	}
	else
	{
		return numSides;
	}
}