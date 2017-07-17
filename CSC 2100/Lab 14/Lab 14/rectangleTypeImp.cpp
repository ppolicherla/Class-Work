#include "rectangleType.h"
using namespace std;
//definitions for the dimension functions
void rectangleType::setDimension(double l, double w)
{
	length = l;
	width = w;
}

double rectangleType::getLength() const
{
	return length;
}

double rectangleType::getWidth() const
{
	return width;
}

double rectangleType::area() const
{
	return length*width;
}

double rectangleType::perimeter() const
{
	return ((2*length)+(2*width));
}
//rectangle type arithmatic operators definitions
rectangleType rectangleType::operator+(const rectangleType &rect) const
{
	rectangleType temp;
	temp.length = length + rect.length;
	temp.width = width + rect.width;
	return temp;
}

rectangleType rectangleType::operator-(const rectangleType &rect) const
{
	rectangleType temp;
	temp.length = abs(length - rect.length);
	temp.width = abs(width - rect.width);
	return temp;
}

rectangleType rectangleType::operator*(const rectangleType &rect) const
{
	rectangleType temp;
	temp.length = length * rect.length;
	temp.width = width * rect.width;
	return temp;
	
}

rectangleType rectangleType::operator++()
{
	++length;
	++width;
	return *this;
}

rectangleType rectangleType::operator--()
{
	--length;
	--width;
	return *this;
}
//boolean function definitions
bool rectangleType::operator==(const rectangleType &rect) const
{
	return (length == rect.length && width == rect.width);
}

bool rectangleType::operator!=(const rectangleType &rect) const
{
	return (length != rect.length && width != rect.width);
}

bool rectangleType::operator<=(const rectangleType &rect) const
{
	return (length <= rect.length && width <= rect.width);
}

bool rectangleType::operator<(const rectangleType &rect) const
{
	return (length < rect.length && width < rect.width);
}

bool rectangleType::operator>=(const rectangleType &rect) const
{
	return (length >= rect.length && width >= rect.width);
}

bool rectangleType::operator>(const rectangleType &rect) const
{
	return (length > rect.length && width > rect.width);
}
//constructor definitions
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}
