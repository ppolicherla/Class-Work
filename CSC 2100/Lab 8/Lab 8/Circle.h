#ifndef CIRCLE_H
#define CIRCLE_H
#include<iostream>
using namespace std; 


class circle
{
public:
	void print();

	void setRadius(double r);
	//Function to set the radius.
	//Postcondition: if (r >= 0) radius = r;
	//               otherwise radius = 0;

	double getRadius();
	//Function to return the radius.
	//Postcondition: The value of radius is returned.

	double area();
	//Function to return the area of a circle.
	//Postcondition: Area is calculated and returned.

	double circumference();
	//Function to return the circumference of a circle.
	//Postcondition: Circumference is calculated and returned.

	circle(double r = 0);
	//Constructor with a default parameter.
	//Radius is set according to the parameter.
	//The default value of the radius is 0.0;
	//Postcondition: radius = r;

private:
	double radius;
};

#endif