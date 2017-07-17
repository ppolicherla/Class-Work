#include<iostream>
#include<cmath>
using namespace std;

class rectangleType
{
public:
	void setDimension(double l, double w);
	double getLength() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;
	//operators to preform quick arithmatic with rectangle objects
	rectangleType operator+(const rectangleType &) const;
	rectangleType operator-(const rectangleType &) const;
	rectangleType operator*(const rectangleType &) const;
	rectangleType operator++();
	rectangleType operator--();
	//boolean operators to compare to rectangle objects
	bool operator ==(const rectangleType&) const;
	bool operator !=(const rectangleType&) const;
	bool operator <=(const rectangleType&) const;
	bool operator <(const rectangleType&) const;
	bool operator >=(const rectangleType&) const;
	bool operator >(const rectangleType&) const;
	//constructors
	rectangleType();
	rectangleType(double l, double w);

protected:
	double length;
	double width;

};