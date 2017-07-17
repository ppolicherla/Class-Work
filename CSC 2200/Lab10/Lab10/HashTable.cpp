#include <iostream>

#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
	
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[initTableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& source)
{
	tableSize = 0;
	dataTable = NULL;
	*this = other;
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>&
HashTable<DataType, KeyType>::operator=(const HashTable& source) 
{
	if (this != &other)
	{
		clear();
		if (!other.isEmpty())
		{
			copyTable(other);
		}
	}
	return *this;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) 
{
	int index = 0;

	if (dataTable != NULL)
	{
		delete[] dataTable;
		dataTable = NULL;
	}
	tableSize = source.tableSize;

	dataTable = new BSTree<DataType, KeyType>[tableSize];

	for (index = 0; index < tableSize; index++)
	{
		dataTable[index] = source.dataTable[index];
	}
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	delete[] dataTable;
	dataTable = NULL;
	tableSize = 0;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) 
{
	unsigned int index = 0;

	index = DataType::hash(newDataItem.getKey());

	index %= tableSize;

	dataTable[index].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) 
{
	
	bool del = false;
	unsigned int index = 0;

	index = DataType::hash(deleteKey);

	index %= tableSize;

	del = dataTable[index].remove(deleteKey);

	return del;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey,
	DataType& returnItem) const
{
	bool retrive = false;
	unsigned int index = 0;

	index = DataType::hash(searchKey) % tableSize;

	retrive = dataTable[index].retrieve(searchKey, returnItem);

	return retrive;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() 
{
	int index = 0;

	for (index = 0; index < tableSize; index++)
	{
		dataTable[index].clear();
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const 
{
	
	bool empty = true;
	int index = 0;

	for (index = 0; index < tableSize; index++)
	{
		if (!dataTable[index].isEmpty())
		{
			empty = false;
			break;
		}
	}
	return empty;
}

#include <cmath>

template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const 
{
	int total = 0;

	for (int i = 0; i < tableSize; ++i) {
		total += dataTable[i].getCount();
	}

	double average = total / tableSize;
	double sum = 0.0;

	for (int i = 0; i < tableSize; ++i) {
		int size = dataTable[i].getCount();
		sum += (size - average) * (size - average);
	}

	return sqrt(sum / (tableSize - 1));
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const 
{
	for (int i = 0; i < tableSize; ++i) {
		cout << i << ": ";
		dataTable[i].writeKeys();
	}
}
