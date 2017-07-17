#include <iostream>

using namespace std;

class largeIntegers
{
public:


	largeIntegers(int list[], int length = 0); // constructor
	void setNum(int list[], int length); // set the dynamic array 
	void printNum(); // print out the array
	void copyNum(const largeIntegers& right); // copy
	~largeIntegers();


private:

	int *number; // dynamic array
	int numOfDigits; // lenght of dynamic array

};
