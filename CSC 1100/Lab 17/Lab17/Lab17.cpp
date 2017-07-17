//Programmed by: Pavan Policherla
//Lab 17
// 7/21/2015

#include<iostream>
using namespace std;

enum triangleType{scalene, isosceles, equilateral, noTriangle};
triangleType triangleShape(double side1, double side2, double side3);
void print();

int main()
{
	double side1, side2, side3;
	cout << "please enter the lengths of the side of a triangle: ";
	cin >> side1 >> side2 >> side3;
	switch (triangleShape(side1, side2, side3))
	{
	case equilateral:
		cout << "the triangle is equilateral" << endl;
		break;
	case scalene:
		cout << "the triangle is scalene" << endl;
		break;
	case isosceles:
		cout << "the triangle is isosceles" << endl;
		break;
	case noTriangle:
		cout << "this is not a triangle" << endl;
		break;
	}
}

triangleType triangleShape(double side1, double side2, double side3)
{
	if (side1 == side2&&side2 == side3)
	{
		return equilateral;
	}
	else if (side1 < side2&&side2 < side3||side1<side3&&side3<side2||side2<side1&&side1<side3||side2<side3&&side3<side1||side3<side1&&side1<side2||side3<side2&&side2<side1)
	{
		return scalene;
	}
	else if (side1 == side2&&side3 < side1||side1==side3&&side1<side2||side3==side2&&side3<side1)
	{
		return isosceles;
	}
	else
	{
		return noTriangle;
	}
}