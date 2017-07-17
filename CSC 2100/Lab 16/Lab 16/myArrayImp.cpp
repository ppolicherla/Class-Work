
#include <iostream>
#include <cassert> 
#include "myArray.h"

using namespace std;
template<class arr>
myArray<arr>::myArray(int uB)
{
	if (uB <= 0)
	{
		cout << "Array size must be positive" << endl;
		cout << "Creating an array of size 5: (0-4)" << endl;
		lowerBound = 0;
		upperBound = 4;
	}
	else
	{
		lowerBound = 0;
		upperBound = uB;
	}

	aPtr = new int[upperBound];

	for (int i = 0; i < upperBound; i++)
		aPtr[i] = 0;
}
template<class arr>
myArray<arr>::myArray(int lB, int uB)
{
	if (lB > uB)
	{
		cout << "Lower Bound must be less than or equal "
			<< "to upperBound" << endl;
		cout << "Creating an array of size 5: (0-4)" << endl;
		lowerBound = lB;
		upperBound = uB;
	}
	else
	{
		lowerBound = lB;
		upperBound = uB;
	}

	aPtr = new int[uB - lB];

	for (int i = 0; i <uB - lB; i++)
		aPtr[i] = 0;
}
template<class arr>
myArray<arr>::myArray()
{
	lowerBound = 0;
	upperBound = 5;

	aPtr = new int[upperBound - lowerBound];

	for (int i = 0; i < upperBound - lowerBound; i++)
		aPtr[i] = 0;
}
template<class arr>
myArray<arr>::myArray(const myArray<arr> &copy)  //copy constructor
{
	upperBound = copy.upperBound;
	lowerBound = copy.lowerBound;

	aPtr = new int[upperBound - lowerBound];

	for (int i = 0; i < upperBound - lowerBound; i++)
		aPtr[i] = copy.aPtr[i];
}
template<class arr>
myArray<arr>::~myArray()  //destructor
{
	delete[] aPtr;
}

//overload the assignment operator
template<class arr>
const myArray<arr>& myArray<arr>::operator=(const myArray &right)
{
	if (this != &right) //avoid self copy
	{
		delete[] aPtr;

		upperBound = right.upperBound;
		lowerBound = right.lowerBound;

		aPtr = new int[upperBound - lowerBound];

		for (int i = 0; i < upperBound - lowerBound; i++)
			aPtr[i] = right.aPtr[i];
	}

	return *this;
}
template<class arr>
int& myArray<arr>::operator[] (int index)
{
	assert(lowerBound <= index && index < upperBound);
	return aPtr[index - lowerBound];
}
template<class arr>
const int & myArray<arr>::operator[](int index) const
{
	assert(lowerBound <= index && index < upperBound);
	return aPtr[index - lowerBound];
}

//overload relational operators
template <class arr>
bool myArray<arr>::operator==(const myArray &right) const
{
	if (upperBound != right.upperBound &&
		lowerBound != right.lowerBound)
		return false;
	else
		for (int i = 0; i < upperBound - lowerBound; i++)
			if (aPtr[i] != right.aPtr[i])
				return false;
	return true;
}
template<class arr>
bool myArray<arr>::operator !=(const myArray &right) const
{
	return(!(*this == right));
}
