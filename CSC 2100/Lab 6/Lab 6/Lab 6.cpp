//programmed by: Pavan Policherla
//Lab 6
// 9/30/10

#include<iostream>
#include<string>
#include"personType.h"
using namespace std;

int main()
{
	int memID1=1,memID2=2;
	int spent1=350, spent2= 400, newSpent1, newSpent2;
	int numBooks1=4, numBooks2=5, newBooks1, newBooks2;
	string name1="Paul Smith", name2="Jane Smith", newName1, newName2;

	personType person1(name1, memID1, numBooks1, spent1);
	cout << "Person 1 name: "<<person1.getName() << endl;
	cout << "Enter a new name: ";
	cin >> newName1;
	person1.setName(newName1);
	person1.printName();
	personType person2(name1, memID1, numBooks1, spent1);
	cout << endl << endl << "Books Bought: "<<person1.getBooks()<< endl;
	cout << endl << "Enter a new amount of books to be bought: ";
	cin >> newBooks1;
	person1.setBooks(newBooks1);
	person1.printBooks();
	personType person3(name1, memID1, numBooks1, spent1);
	cout << endl << "Amount spent: "<<person1.getAmount() << endl;
	cout << endl << "Enter a new amount to be spent: ";
	cin >> newSpent1;
	person1.setAmount(newSpent1);
	person1.printAmount();
	personType person4(name1, memID1, numBooks1, spent1);
	cout << endl << endl << "the new name is:" << person1.getName() << endl;
	cout << "the new number of books bought: " << person1.getBooks() << endl;
	cout << "the new amount spent: " << person1.getAmount() << endl;
	



	
}