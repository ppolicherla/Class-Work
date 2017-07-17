
// include your headers here
#include "date.h"
using namespace std;
Date::Date(int mm, int dd, int yyyy)
{
	//write the constructor code
	month = mm;
	day = dd;
	year = yyyy;
}

int Date::operator==(Date &date2)
{
	// this is a sample code for == operator
	if (day == date2.day && month == date2.month && year == date2.year)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Date::operator>=(Date &date2)
{
	// write your own code for >= operator
	if (year>=date2.year)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else if (year == date2.year && month >= date2.month)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else if (year == date2.year && month == date2.month && day >= date2.day)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else
	{
		cout << "FALSE!!!!!!" << endl;
		return 0;
	}
}

int Date::operator<=(Date &date2)
{
	// write your own code for <= operator
	if (year <= date2.year)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else if (year == date2.year && month <= date2.month)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else if (year == date2.year && month == date2.month && day <= date2.day)
	{
		cout << "TRUE!!!!!!" << endl;
		return 1;
	}
	else
	{
		cout << "FASLE!!!!!!" << endl;
		return 0;
	}
}