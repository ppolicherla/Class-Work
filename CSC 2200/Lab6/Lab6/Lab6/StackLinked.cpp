//--------------------------------------------------------------------
//
//  Laboratory 6                                       StackLinked.cpp
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_CPP
#define STACKLINKED_CPP

#include <iostream>

#include "StackLinked.h"


//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) 
 
// Creates an empty stack. The parameter maxNumber is provided for 
// compatability with the array implementation and is ignored.

{

	top = 0;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)

// Copy constructor for linked stack

{
	if (!other.isEmpty())
	{
		top = new StackNode(other.top->dataItem, 0);
		StackNode *otherTemp = other.top->next;
		StackNode *thisTemp = 0, *thisPrevious = top;


		while (otherTemp != 0)
		{
			thisTemp = new StackNode(otherTemp->dataItem, 0);
			thisPrevious->next = thisTemp;
			thisPrevious = thisTemp;
			otherTemp = otherTemp->next;
		}

	}
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)

// Overloaded assignment operator for the StackLinked class.
// Because this function returns a StackLinked object reference,
// it allows chained assignment (e.g., stack1 = stack2 = stack3).

{
              
	if (!other.isEmpty())
	{		
		top = new StackNode(other.top->dataItem, 0);
		StackNode *otherTemp = other.top->next;
		StackNode *thisTemp = 0, *thisPrevious = top;

		while (otherTemp != 0)
		{
			thisTemp = new StackNode(otherTemp->dataItem, 0);
			thisPrevious->next = thisTemp;
			thisPrevious = thisTemp;
			otherTemp = otherTemp->next;
		}
	}

	return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
StackLinked<DataType>::~StackLinked() 

// Destructor. Frees the memory used by a stack.

{
	clear();
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error) 

// Inserts newDataItem onto the top of a stack.

{
	top = new StackNode(newDataItem, top);
}

//--------------------------------------------------------------------

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error) 

// Removes the topmost item from a stack and returns it.

{
	
	StackNode* temp = top;
	StackNode* value = temp;
	top = top->next;
	delete temp;
	return value->dataItem;
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::clear() 

// Removes all the data items from a stack.

{
	StackNode *temp;
	while (top != 0) 
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const 

// Returns true if a stack is empty. Otherwise, returns false.

{
	return top == 0;
}

//--------------------------------------------------------------------

template <typename DataType>
bool StackLinked<DataType>::isFull() const 

// Returns true if a stack is full. Otherwise, returns false. 

{
    return false;
}

//--------------------------------------------------------------------

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }
}

#endif		//#ifndef STACKLINKED_CPP
