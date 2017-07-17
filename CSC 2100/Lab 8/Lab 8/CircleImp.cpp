#include "Circle.h"
#include <cmath>
using namespace std;

void circle::print()
{
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area() << endl;
	cout << "Circumference: " << circumference() << endl;
}

void circle::setRadius(double r)
{
	radius = r;
}

double circle::getRadius()
{
	return radius;
}

double circle::area()
{
	double pi = 3.14;
	double area;
	area = pi*(pow(radius, 2));
	return area;
}

double circle::circumference()
{
	double pi = 3.14;
	double cir;
	cir = pi*radius * 2;
	return cir;
}

circle::circle(double r)
{
	radius = r;
}