//--------------------------------------------------------------------
//  Laboratory 5                                        ListLinked.cpp
//
//  
//--------------------------------------------------------------------

#ifndef LISTLINKED_CPP
#define LISTLINKED_CPP

using namespace std;

#include <iostream>			// For showStructure

#include "ListLinked.h"

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData,
				   ListNode* nextPtr)
// Creates a list node containing item elem and next pointer
// nextPtr.
    
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(int ignored)

// Creates an empty list. The argument is included for compatibility
// with the array implementation (maxSize specifier) and is ignored.
    
{
	head = NULL;
	cursor = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::List(const List& other)
    
// Copy constructor. Creates a list which is equivalent in content
// to the "other" list.

{
	ListNode* temp = other.head;
	while (temp != NULL)
	{
		this->dataItem = temp->dataItem;
		this->next = temp->next;
		gotoNext();
		temp = temp->next;
	}

	*this = other;

}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)

// Overloaded assignment operator. Reinitializes the list to be 
// equivalent in content to the "other" list.

{
	ListNode* temp = other.head;
	while (temp != NULL)
	{
		insert(temp->dataItem);
		gotoNext();
		temp = temp->next;
	}

	return *this;
}

//--------------------------------------------------------------------

template <typename DataType>
List<DataType>::~List() 

// Destructor. Frees the memory used by a list.

{
	ListNode* del;
	ListNode* temp = head;

	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
	head = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
	if (isFull())
	{
		throw logic_error("List is full");
	}
	if (!isEmpty())
	{
		ListNode* temp = cursor;
		cursor = new ListNode(newDataItem, temp->next);
		temp->next = cursor;
	}
	else if (isEmpty())
	{
		head = new ListNode(newDataItem, 0);
		cursor = head;
	}
    
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::remove() throw (logic_error) 

// Removes the item marked by the cursor from a list. Moves the
// cursor to the next item in the list. Assumes that the first list
// item "follows" the last list item.

{
	ListNode* del;
	if (isEmpty())
	{
		throw logic_error("List is empty!");
	}

	if (cursor == head)
	{
		del = head;
		head = head->next;
		gotoNext();
		delete del;
	}
	else
	{
		ListNode* pre;
		del = cursor;
		pre = head;
		while (pre->next != cursor)
		{
			pre = pre->next;
		}
		if (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		else
		{
			cursor = head;
		}
		pre->next = del->next;
		delete del;
		del = NULL;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
	if (cursor == NULL)
	{
		throw logic_error("nothing here");
	}
	if (head != NULL)
	{
		cursor->dataItem = newDataItem;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::clear() 

// Removes all the items from a list. Sets head and cursor to 0.

{
	cursor = head;
	ListNode* clear;
	while (cursor != NULL)
	{
		clear = head;
		head = head->next;
		cursor = cursor->next;
		delete clear;
		break;
	}
	head = NULL;
	cursor = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::isEmpty() const 

// Returns true if a list is empty. Otherwise, returns false.

{
	if (head == NULL&&cursor == NULL)
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
bool List<DataType>::isFull() const 

// Returns true if a list is full. Otherwise, returns false.

{
    return false;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)

// If a list is not empty, then moves the cursor to the beginning of
// the list. If list is empty, throws logic error.

{
	cursor = head;
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)

// If a list is not empty, then moves the cursor to the end of the
// list. Otherwise, throws logic_error.

{
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise, 
// leaves cursor unmoved and returns false.

{
	if (cursor->next != NULL)
	{
		cursor = cursor->next;
		return true;
	}
	else
	{
		throw logic_error("at the end or list is empty");
		return false;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	if (cursor != head&& head != NULL)
	{
		ListNode* prior = head;
		while (prior->next != cursor)
		{
			prior = prior->next;
		}
		cursor = prior;
		return true;
	}
	else
	{
		throw logic_error("at the beginning of the list or the list is empty");
		return false;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)

// Returns the item marked by the cursor. Requires that list is not empty.

{
	if (!isEmpty())
	{
		return cursor->dataItem;
	}
	else
	{
		throw logic_error("the list is empty so no cursor");
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    if ( isEmpty() )
    {
       cout << "Empty list" << endl;
    } 
    else
    {
	for (ListNode* temp = head; temp != 0; temp = temp->next) {
	    if (temp == cursor) {
		cout << "[";
	    }

	    // Assumes that dataItem can be printed via << because
	    // is is either primitive or operator<< is overloaded.
	    cout << temp->dataItem;	

	    if (temp == cursor) {
		cout << "]";
	    }
	    cout << " ";
	}
	cout << endl;
    }
}

//--------------------------------------------------------------------
//
//                        Programming Exercises 2 and 3
//
//--------------------------------------------------------------------

// Programming exercise 2

template < typename DataType >
void List<DataType>:: moveToBeginning() throw ( logic_error )

// Removes the item marked by the cursor from a list and
// reinserts it at the beginning of the list. Moves the cursor to the
// beginning of the list.

{
	if (cursor != head && head != NULL)  
	{
		ListNode* find = head;

		while (find->next != cursor)  
		{
			find = find->next;
		}

		find->next = cursor->next;
		cursor->next = head;
		head = cursor;
	}
	else
	{
		throw logic_error("list is empty");
	}
}

//--------------------------------------------------------------------
// Programming exercise 3

template < typename DataType >
void List<DataType>:: insertBefore ( const DataType &newDataItem )
    throw ( logic_error )

// Inserts newDataItem before the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) item in the list.
// In either case, moves the cursor to newDataItem.

{
	if (isEmpty()) 
	{
		head = new ListNode(newDataItem, 0);
		cursor = head;
	}
	else  
	{
		if (cursor == head)  
		{
			ListNode *newNode = new ListNode(newDataItem, head);
			head = newNode;
			cursor = newNode;
		}
		else 
		{
			gotoPrior();
			insert(newDataItem);
		}
	}
}

#endif		// #ifndef LISTLINKED_CPP
