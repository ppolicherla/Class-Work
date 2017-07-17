//Programmed By: Pavan Policherla
//Lab 8
//10/7/2015
#include "SwimmingPool.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;

int main()
{
	int length, depth, width, rate; //variables that will define the pool object
	//code that will ask the user to define the variables of the pool
	cout << "Enter the length: ";
	cin >> length;
	cout << "Enter the width: ";
	cin >> width;
	cout << "Enter the depth: ";
	cin >> depth;
	cout << "Enter the rate to fill the pool: ";
	cin >> rate;
	swimmingPool swim(length, width, depth, rate); //making the pool with user inputted variables
	swim.fillTime(); //function call to find out how long it will 
	
	int height, radius;//variables to create the cylinder object
	// lines that will have the user define the cylinder variables
	cout << "Please enter the height of the cylinder: ";
	cin >> height;
	cout << "Please enter the radius of the base: ";
	cin >> radius;
	cylinder cylinder(height, radius);//constructor for the cylinder object
	cylinder.setRadius(radius);//function that will redefine the radius of the base
	cout << "The area of the cylinder is: " << cylinder.surfaceArea() << endl;
	cout << "The volume of the cylinder is: " << cylinder.volume() << endl;
}