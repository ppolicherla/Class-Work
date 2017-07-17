#include "Circle.h"
using namespace std;

class cylinder: public circle
{
public:
	cylinder(int high, int rad);
	// constructor for the cylinder object
	double volume();
	//function that will calculate the volume of the cylinder
	//this funciton will need to use the area of the cicle base 
	double surfaceArea();
	//function that will find the surface area of the cylinder
	//will require the circumference and 2 times the area of the circle to complete
	void setHeight(int high);
	//function that will redefine the height of the cylinder
	void setRadius(double r);
	//function that will redifine the radius of the base of the cylinder.
	void setCenter();
	//I honestly don't understand this function please comment to elaborate.
private:
	int height;
};