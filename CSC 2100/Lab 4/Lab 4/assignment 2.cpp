//programmed by: Pavan Policherla
// lab 4 assignment 2
// 9/23/2015

#include<iostream>
#include<cmath>
using namespace std;
double distance(int x1, int x2, int y1, int y2);
double radius(int x1, int x2, int y1, int y2);
double circ(int x1, int x2, int y1, int y2);
double area(int x1, int x2, int y1, int y2);
int main()
{
	int x1, x2, y1, y2;
	cout << "Please enter x1: ";
	cin >> x1;
	cout << endl << "Please enter y1: ";
	cin >> y1;
	cout << endl << "Please enter x2: ";
	cin >> x2;
	cout << endl << "Please enter y2: ";
	cin >> y2;
	cout << endl;

	cout << "The distance is: " << distance(x1, x2, y1, y2) << endl;
	cout << "The radius is: " << radius(x1, x2, y1, y2) << endl;
	cout << "The circumference is: " << circ(x1, x2, y1, y2) << endl;
	cout << "The area is: " << area(x1, x2, y1, y2) << endl << endl;

}

double distance(int x1, int x2, int y1, int y2)
{
	double distance;

	distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	return distance;
}

double radius(int x1, int x2, int y1, int y2)
{
	double radius;

	radius = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	return radius;
}

double circ(int x1, int x2, int y1, int y2)
{
	double circ;
	double r = radius(x1, x2, y1, y2);
	double pi = 3.1416;
	circ = 2 * pi*r;
	return circ;
}

double area(int x1, int x2, int y1, int y2)
{
	double area;
	double r = radius(x1, x2, y1, y2);
	double pi = 3.1416;
	area = pi*pow(r, 2);
	return area;
}
