//programmed by: Pavan Policherla
//Lab 11 question 1
//6/28/2015

#include <iostream>
#include<iomanip>
#define _USE_MATH_DEFINES
#include<cmath>
#include<math.h>
using namespace std;

double find_radius(int x1, int y1, int x2, int y2)  //function to find the radius that will take the x and y coordinates of two points(the center and a point on the circle) and will return the radius of the circle
{
	double radius = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));//the varible to represent the radius and the calculation to find the radius
	return radius;//returns the value of the radius variable.
}

double find_distance(int x1, int y1, int x2, int y2)//function that takes the x and y values of two points and calculates the distance between them.
{
	double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));//the variable for distance and the equation to find it
	return distance;//returns the distance variable.
}

double find_circumference(double radius)//takes the radius value and calculates the circumference.
{
	double circumference = 2 * M_PI*radius;//calculates the value for the variable circumference
	return circumference;//returns the circumference variable.
}

double find_area(double radius)//takes the radius value and calculates the area
{
	double area = M_PI*pow((radius), 2);//calculates the area of the circle for the area variable.
	return area;//returns the area variable.
}

int main()// the main function that will call the previously defined functions
{
	int x1, y1, x2, y2; //the variables used to represent the x and y coordinates of the two points used
	double distance, radius, area, circumference;// the variables used to represent the values found from the coordinates entered.
	
	cout << "please enter the x and y coordinates for the center of the circle: ";//prompt to ask the user for the x and y coordinates of the center of the circle.
	cin >> x1 >> y1;//entry of the x and y coordinates of the center of the circle.
	cout << "Please enter the x and y coordinates for point on the circle: ";//prompt to ask the user for the x and y coordinates of a point on the circle.
	cin >> x2 >> y2;//entry of the x and y coordinates of the point on the circle
	cout << endl;
	
	distance = find_distance(x1, y1, x2, y2);//use of the distance function to find the distance between the two points.
	cout <<"The distance between the two points is: " << distance << endl;//outputting the distance between the two points.
	radius = find_radius(x1, y1, x2, y2);//use of the radius function to find the radius of the circle.
	cout << "The radius is: " << radius << endl;//outputting the value of the radius for the circle given the two points.
	double diameter = radius * 2;//formula to calculate the diameter.
	cout << "The diameter is: " << diameter << endl;//outputting the value of the diameter given the radius.
	circumference = find_circumference(radius);//use of the circumference function to find the circumference.
	cout << "The circumference is: " << circumference << endl;//outputting the value of the circumference of the circle.
	area = find_area(radius);//use of the area function to find the area of the circle.
	cout << "The area is: " << area << endl;//outputting the value of the area for the circle.
	
}