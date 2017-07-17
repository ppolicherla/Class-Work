#include<iostream>
#include<string>
using namespace std;

template <class arr>

class DynamicStringArray
{
public:
	DynamicStringArray();//default constructor
	int getSize();//returns the size of the array
	void addEntry(arr element);//adds elements to the array and will increase the size of the array with each new entry
	bool deleteEntry(arr input);//removes elements from the array and decreases the size as each element is remove
	arr getEntry(int i);//returns a specific entry in the array
	DynamicStringArray(const DynamicStringArray& other);//copy constructor
	DynamicStringArray& operator=(const DynamicStringArray& other);//overload operator
	~DynamicStringArray();//destructor
//private member variables.
private:
	arr *dynamicArray;
	int size;

};