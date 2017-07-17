#include "Cylinder.h"
#include "Circle.h"
using namespace std;



double cylinder::volume() 
{
	return (area()*height);
}

double cylinder::surfaceArea()
{
	return ((circumference()*height) + (2 * area()));
}

void cylinder::setHeight(int high)
{
	height = high;
}

void cylinder::setRadius(double r)
{
	circle::setRadius(r);
}

cylinder::cylinder(int high, int rad) 
	: circle(rad=0)
{
	setHeight(high);
}