#include "largeIntegers.h"
#include <iostream>
using namespace std;

largeIntegers::largeIntegers(int list[], int length)
{
	numOfDigits = length;
	number = new int[numOfDigits];
	for (int i = 0; i < numOfDigits; i++)
	{
		number[i] = list[i];
	}
}

void largeIntegers::setNum(int list[], int length)
{
	numOfDigits = length;
	number = new int[numOfDigits];
	for (int i = 0; i < numOfDigits; i++)
	{
		number[i] = list[i];
	}
}

void largeIntegers::printNum()
{
	if (number == NULL)
	{
		cout << "NULL";
		cout << endl << endl;
	}
	else
	{
		for (int i = 0; i < numOfDigits; i++)
		{
			cout << number[i];
		}
		cout << endl << endl;
	}
}

void largeIntegers::copyNum(const largeIntegers& right)
{
	numOfDigits = right.numOfDigits;
	number = new int[numOfDigits];
	for (int i = 0; i < numOfDigits; i++)
	{
		number[i] = right.number[i];
	}
}

largeIntegers::~largeIntegers()
{
	delete []number;
	number = NULL;
	numOfDigits = 0;
}