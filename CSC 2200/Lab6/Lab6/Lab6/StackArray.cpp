//--------------------------------------------------------------------
//
//  Laboratory 6                                       StackArray.cpp
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_CPP
#define STACKARRAY_CPP

#include <iostream>

#include "StackArray.h"

//--------------------------------------------------------------------

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber)

// Creates an empty stack. 

{
	top = -1;
	maxSize = maxNumber;
	dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)

// Copy constructor for linked stack

{
	maxSize = other.maxSize;
	top = other.top;
	dataItem = new DataType[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		dataItem[i] = other.dataItems[i];
	}
}

//--------------------------------------------------------------------

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)

// Overloaded assignment operator for the StackArray class.
// Because this function returns a StackArray object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
	if (this != &other)
	{
		return *this;
	}

	if (maxSize < other.maxSize) 
	{
		delete[] dataItems;
		dataItems = new DataType[other.maxSize];
	}

	maxSize = other.maxSize;
	top = other.top;
	for (int i = 0; i <= top; i++)
	{
		dataItems[i] = other.dataItems[i];
	}

	return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
StackArray<DataType>::~StackArray() 

// Frees the memory used by a stack.

{
	delete[] dataItems;
}

//--------------------------------------------------------------------

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error) 

// Inserts newDataItem onto the top of a stack.

{
	
	dataItems[top++] = newDataItem;
}

//--------------------------------------------------------------------

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error) 

// Removes the topmost data item from a stack and returns it.

{
	if (top == -1)
	{
		throw logic_error("Stack is empty.");
	}

	DataType temp;

	temp = dataItems[--top];

	return temp;
}

//--------------------------------------------------------------------

template <typename DataType>
void StackArray<DataType>::clear() 

// Removes all the data items from a stack.

{
	//top = -1;
	for (int i = 0; i < maxSize; i++)
	{
		pop();
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackArray<DataType>::isEmpty() const 

// Returns true if a stack is empty. Otherwise, returns false.

{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackArray<DataType>::isFull() const 

// Returns true if a stack is full. Otherwise, returns false.

{
	if (top == MAX_STACK_SIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}

#endif		// #ifndef STACKARRAY_CPP
