//Programmed By: Pavan Policherla
// Lab 14
// 10/28/2015

#include<iostream>
#include "rectangleType.h"
using namespace std;

int main()
{
	//creating rectangletype objects
	double l1 = 36, l2 = 52;
	double w1 = 24, w2 = 32;
	rectangleType rect1(l1, w1);
	rectangleType rect2(l2, w2);
	//testing double functions
	cout << rect1.getLength() << endl;
	cout << rect2.getWidth() << endl;
	cout << rect1.area() << endl;
	cout << rect2.perimeter() << endl;
	//testing arithmetic operators
	rectangleType tempRect;
	tempRect = rect1+rect2;
	cout << tempRect.getLength()<< " " << tempRect.getWidth()<< endl;
	tempRect = rect1-rect2;
	cout << tempRect.getLength() << " " << tempRect.getWidth() << endl;
	tempRect = rect1*rect2;
	cout << tempRect.getLength() << " " << tempRect.getWidth() << endl;
	//test incrementer and decrementer operations
	++rect1;
	cout << rect1.getLength() << " " << rect1.getWidth() << endl;
	--rect2;
	cout << rect2.getLength() << " " << rect2.getWidth() << endl;
	//testing boolean functions
	if (rect1 == rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	if (rect1 != rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	if (rect1 <= rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	if (rect1 < rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	if (rect1 >= rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	if (rect1 > rect2)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE!" << endl;
	}
	
}
