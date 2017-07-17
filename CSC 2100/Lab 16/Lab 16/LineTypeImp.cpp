
#include <iostream>
#include <cmath>
#include <iomanip>

#include "lineType.h"

using namespace std;


void lineType::setLine(double a, double b, double c)
{
	xCoeff = a;
	yCoeff = b;

	if (a == 0 && b == 0)
		constTerm = 0;
	else
		constTerm = c;
}


//vertical line
bool lineType::operator+() const
{
	if (yCoeff == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//horizontal line
bool lineType::operator-()const
{
	if (xCoeff == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//equal lines
bool lineType::operator==(const lineType& otherLine) const
{
	if ((xCoeff / yCoeff) == (otherLine.xCoeff / otherLine.yCoeff)&&constTerm==otherLine.constTerm)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//parallel lines
bool lineType::operator||(const lineType& otherLine) const
{
	if ((xCoeff / yCoeff) == (otherLine.xCoeff / otherLine.yCoeff))
	{
		return true;
	}
	else
	{
		return false;
	}
}


lineType::lineType(double a, double b, double c)
{
	setLine(a, b, c);
}

ostream& operator<<(ostream& osObject,
	const lineType& line)

{
	if (line.xCoeff != 0)
		osObject << line.xCoeff << "x ";

	if (line.yCoeff != 0)
	{
		if (line.yCoeff < 0)
			osObject << "- ";
		else
			osObject << "+ ";
		osObject << fabs(line.yCoeff) << "y ";
	}

	osObject << " = " << line.constTerm;

	return osObject;
}

istream& operator>>(istream& isObject, lineType& line)
{
	char ch;

	isObject >> ch;
	isObject >> line.xCoeff;
	isObject >> ch;
	isObject >> line.yCoeff;
	isObject >> ch;
	isObject >> line.constTerm;
	isObject >> ch;

	return isObject;
}