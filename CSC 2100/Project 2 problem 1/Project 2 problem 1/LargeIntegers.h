#include<iostream>
#include<string>
#define DIGITS 100
using namespace std;

class largeIntegers
{
public:
	largeIntegers();//default constructor 
	void input();//function to enter data
	void output();//function to output data

	// overloading operators
	largeIntegers operator+(const largeIntegers&);
	largeIntegers operator-(const largeIntegers&);
	largeIntegers operator*(const largeIntegers&);

	int operator ==(const largeIntegers&) ;

private:
	int large[DIGITS];
	int length;
};
