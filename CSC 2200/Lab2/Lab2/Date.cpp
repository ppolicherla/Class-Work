
#include "Date.h"

Date::Date()
{
}

Date::Date(int day, int month, int year) throw (logic_error)
{
}

int Date::getDay() const
{
	return -1;
}

int Date::getMonth() const
{
	return -1;
}

int Date::getYear() const
{
	return -1;
}

//in show2.cpp
//void showStructure() const;


bool Date::isLeapYear(int year)
{
	return false;
}

int Date::daysInMonth(int month, int year)
{
	return -1;
}

int Date::getDayOfWeek() const
{
	return -1;
}

bool Date::operator<(const Date& rhs) const
{
	return false;
}

bool Date::operator==(const Date& rhs) const
{
	return false;
}

bool Date::operator>(const Date& rhs) const
{
	return false;
}

ostream& operator<<(ostream& out, const Date& date)
{
	return out;
}