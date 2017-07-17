#include"Dice.h"
using namespace std;

class LoadedDice:public Dice
{
public:
	LoadedDice();//default constructor
	LoadedDice(int numsides);//constructor with a parameter to determine the number of sides
	virtual int rollDice()const;//overloaded roll dice function
private:
	int numSides;
};