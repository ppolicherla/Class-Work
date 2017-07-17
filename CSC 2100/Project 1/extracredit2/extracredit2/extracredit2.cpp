//Programmed By :Pavan Policherla
//Extra Credit 2
// 11/15/2015

#include<iostream>
#include"Student.h"
using namespace std;

int main()
{
	student a, b;

	a.input();
	cout << "student a's info: " << endl;
	a.output();
	cout << endl;
	b = a;
	student c(b);
	b.output();
	cout << endl;
	c.output();



}