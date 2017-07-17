#ifndef bookType_H
#define bookType_H
#include<string>

using namespace std;

class bookType
{
public:
	void setTitlePrice(string name, int cost);
	//fucntion that will set the private variables title and price to variables name and cost

	void showTitlePrice();
	//function that will output the values assigned to title and price

	bookType();
	//default constructor

	bookType(string name, int cost);
	//constructor that will build the book object with an actual name and cost

private:
	string title;
	int price;
};
#endif