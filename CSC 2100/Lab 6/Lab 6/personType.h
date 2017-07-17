#include<string>
#include<iostream>

using namespace std;
class personType
{

public:
	void setName(string names);
	//function to set the name of the person object

	string getName() const;
	//function to return the name

	void printName() const;
	//function to print the name.

	void setBooks(int numberBooks);
	//function that will set the number of books bought

	int getBooks() const;
	//function to return the number of books bought

	void printBooks() const;
	//function to print out the number of books bought

	void setAmount(int spentAmount);
	//function to set the amount spent

	int getAmount() const;
	//function to return the amount spent

	void printAmount() const;
	//function to print out the amount spent

	personType(string names, int memID, int numberBooks, int spentAmount);
	//constructor for the persontype 

private:
	string name;
	int memberID;
	int numBooks;
	int spent;
};