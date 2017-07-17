
#ifndef H_safeArray
#define H_safeArray 

#include <iostream>

using namespace std;

template < class arr >

class myArray
{
public:
	const myArray& operator= (const myArray &right);
	//overload assignment operator

	myArray(int uB);

	myArray(int lB, int uB);

	myArray();

	myArray(const myArray &copy);
	//copy constructor

	~myArray();
	//destructor

	int &operator[] (int);
	const int &operator[](int) const;

	//overload relational operator
	bool operator== (const myArray &right) const;
	bool operator!= (const myArray &right) const;

private:
	arr *aPtr;  //pointer to int array 
	int lowerBound;
	int upperBound;
};
//#include "myArrayImp.cpp"
#endif  
