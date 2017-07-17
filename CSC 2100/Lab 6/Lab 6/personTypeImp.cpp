#include<iostream>
#include<string>
#include"personType.h"
using namespace std;

void personType::setName(string names)
{
	name = names;
}
//function to set the name of the person object

string personType::getName() const
{
	return name;
}
//function to return the name

void personType::printName() const
{
	cout << name << endl;
}
//function to print the name.

void personType::setBooks(int numberBooks)
{
	numBooks = numberBooks;
}
//function that will set the number of books bought

int personType::getBooks() const
{
	return numBooks;
}
//function to return the number of books bought

void personType::printBooks() const
{
	cout << numBooks << endl;
}
//function to print out the number of books bought

void personType::setAmount(int spentAmount)
{
	spent = spentAmount;
}
//function to set the amount spent

int personType::getAmount() const
{
	return spent;
}
//function to return the amount spent

void personType::printAmount() const
{
	cout << spent << endl;
}
//function to print out the amount spent

personType::personType(string names, int memID, int numberBooks, int spentAmount)
{
	name = names;
	memberID = memID;
	numBooks = numberBooks;
	spent = spentAmount;
}
//constructor for the persontype 