#include "DynamicStringArray.h"
using namespace std;
template <class arr>
DynamicStringArray<arr>::DynamicStringArray()
{
	//initializes the variables to 0
	dynamicArray = NULL;
	size = 0;
}

template <class arr>
int DynamicStringArray<arr>::getSize()
{
	//returns the size
	return size;
}

template <class arr>
void DynamicStringArray<arr>::addEntry(arr element)
{
	//create a new dynamic array
	arr* new_array = new arr[size + 1];
	//copy the elements from the old array into the new array
	int i;
	for (i = 0; i < size; i++)
	{
		new_array[i] = dynamicArray[i];
	}
	//set the last entry of the new array to the string in the parameters
	new_array[i] = element;
	//increment the size
	size++;
	//delete the old array
	delete[] dynamicArray;
	//set the object to the new array created
	dynamicArray = new_array;
}

template <class arr>
bool DynamicStringArray<arr>::deleteEntry(arr input)
{
	//check to see if the input is in the array
	int i;
	for (i = 0; i < size; i++)
	{
		//if found break from the loop
		if (dynamicArray[i] == input)
		{
			break;
		}
	}
	//if we hit the end of the array without finding the input return false
	if (i == size)
	{
		return false;
	}
	//creat a new array of 1 size smaller
	arr *new_array = new arr[size - 1];
	int index = 0;
	//copy elements into the new array
	for (int j = 0; j<size; j++)
	{
		if (dynamicArray[j] != input)
		{
			new_array[index] = dynamicArray[j];
			index++;
		}
	}
	//delete the orignal array
	delete[] dynamicArray;
	size--;
	//make the old array variable equal the new array
	dynamicArray = new_array;
	return true;
}

template <class arr>
arr DynamicStringArray<arr>::getEntry(int i)
{
	//make sure that the index we are looking for is in the array
	if (i< 0 || i > size)
	{
		return NULL;
	}
	//return object at index i
	else
	{
		return dynamicArray[i];
	}
}

template <class arr>
DynamicStringArray<arr>::DynamicStringArray(const DynamicStringArray& other)
{
	//sets the size of the array to the size of the array we are copying from
	size = other.size;
	dynamicArray = new arr[size];
	//copy elements into the created array from the copied array
	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = other.dynamicArray[i];
	}
}

template <class arr>
DynamicStringArray<arr>& DynamicStringArray<arr>:: operator=(const DynamicStringArray& other)
{
	//makes dynamic array the size of the other array
	dynamicArray = new arr[other.getSize()];
	//sets all elements in the new array to the same elements in the other array
	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = other.dynamicArray[i];
	}
}

template <class arr>
DynamicStringArray<arr>::~DynamicStringArray()
{
	//deletes the memory of the dynamic array memory address
	delete[] dynamicArray; 
}