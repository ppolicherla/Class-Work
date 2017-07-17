#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

#include "ListArray.h"

template < typename DataType >
List<DataType>::List(int maxNumber)
{
	maxSize = maxNumber;
	cursor = -1;
	size = 0;
	dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List(const List& source)
{
	maxSize = source.maxSize;
	size = source.size;
	cursor = source.cursor;
	dataItems = new DataType[maxSize];

	for (int i = 0; i<size; i++)
		dataItems[i] = source.dataItems[i];
}

template < typename DataType >
List<DataType>& List<DataType> ::operator= (const List& source)
{
	if (this != &source)
	{
		delete[] dataItems;
		maxSize = source.maxSize;
		size = source.size;
		cursor = source.cursor;
		dataItems = new DataType[maxSize];

		for (int i = 0; i<size; i++)
			dataItems[i] = source.dataItems[i];
	}
	return *this;
}


template < typename DataType >
List<DataType>::~List()
{
	delete[] dataItems;
}


template < typename DataType >
void List<DataType>::insert(const DataType& newDataItem)
{
	if (isFull())
		throw logic_error("List is full");
	else
	{
		size++;
		if (cursor == -1)
		{
			cursor = 0;

		}
		else
		{
			for (int i = size - 2; i>cursor; i--)
				dataItems[i + 1] = dataItems[i];
			cursor++;
		}
		dataItems[cursor] = newDataItem;

	}
}

template < typename DataType >
void List<DataType>::remove() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("List is empty");
	else
	{
		if (cursor == size - 1)
		{
			size--;
			gotoBeginning();
		}
		else
		{
			for (int i = cursor; i<size; i++)
			{
				dataItems[i] = dataItems[i + 1];
			}
			size--;
		}
	}

}


template < typename DataType >
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
		throw logic_error("List is empty");
	else
		dataItems[cursor] = newDataItem;
}

template < typename DataType >
void List<DataType>::clear()
{
	size = 0;
	cursor = -1;
}

template < typename DataType >
bool List<DataType>::isEmpty() const
{
	if (size == 0)
		return true;
	return false;
}

template < typename DataType >
bool List<DataType>::isFull() const
{
	if (size == maxSize)
		return true;
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	else cursor = 0;
}

template < typename DataType >
void List<DataType>::gotoEnd() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	else cursor = size - 1;
}


template < typename DataType >
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	else
	{
		if (cursor<size - 1)
		{
			cursor++;
			return true;
		}
	}
	return false;
}


template < typename DataType >
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	else
	{
		if (cursor != 0)
		{
			cursor--;
			return true;
		}
	}
	return false;
}


template < typename DataType >
DataType List<DataType>::getCursor()const throw (logic_error)
{
	if (isEmpty())
		throw logic_error("list is empty");
	else
		return dataItems[cursor];
}

template < typename DataType >
void List<DataType>::showStructure() const
{
	int j;   // loop counter

	if (size == 0)
		cout << "empty list" << endl;
	// The Ordered List code blows up below. Since this is just debugging
	// code, we check for whether the OrderedList is defined, and if so,
	// print out the key value. If not, we try printing out the entire item.
	// Note: This assumes that you have used the double-inclusion protection
	// in your OrderedList.cpp file by doing a "#ifndef ORDEREDLIST_CPP", etc.
	// If not, you will need to comment out the code in the section under 
	// the "else", otherwise the compiler will go crazy in lab 4.
	// The alternative is to overload operator<< for all data types used in
	// the ordered list.
	else
	{
		cout << "size = " << size
			<< "   cursor = " << cursor << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++) {
			if (j == cursor) {
				cout << "[";
				cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
					.getKey()
#endif
					;
				cout << "]";
				cout << "\t";
			}
			else
				cout << dataItems[j]
#ifdef ORDEREDLIST_CPP
				.getKey()
#endif
				<< "\t";
		}
		cout << endl;
	}
}

template < typename DataType >
void List<DataType>::moveToNth(int n) throw (logic_error)
{
	if (size<n + 1)
		throw logic_error("list does not have enough data items");
	else
	{
		DataType temp;
		temp = getCursor();
		remove();
		gotoBeginning();
		if (n == 0)
		{
			size++;
			for (int i = size - 1; i >= cursor; i--)
				dataItems[i + 1] = dataItems[i];
			dataItems[0] = temp;
		}

		else
		{
			for (int i = 0; i<n - 1; i++)
				gotoNext();
			insert(temp);
		}
	}

}


template < typename DataType >
bool List<DataType>::find(const DataType& searchDataItem) throw (logic_error)
{

	if (isEmpty())
		throw logic_error("list is empty");
	else
	{
		for (int i = cursor; i<size; i++)
		{
			if (dataItems[i] == searchDataItem)
			{
				cursor = i;
				return true;
			}
		}
		
	}
	return false;

}

#endif
