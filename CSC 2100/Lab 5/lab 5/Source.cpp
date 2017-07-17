//programmed by:Pavan Policherla
// lab 5
//9/28/2015

#include<iostream>
#include "Header.h"
using namespace std;

int main()
{
	testClass test1;
	testClass test2(2,4);
	
	cout <<"the sum for test1 is: "<< test1.sum()<< endl;
	test1.print();
	cout <<endl<<"The sum for test2 is: "<< test2.sum ()<< endl;
	test2.print();
}