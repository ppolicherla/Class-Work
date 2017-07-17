#include <iostream>
#include <string>

using namespace std;

class student
{
public:
	student();//default constructor
	~student();//destructor
	student(const student& list);//copy constructor
	void zeros(); //empties the array of class list
	void input(); //Inputs the info for the student object
	void output(); //Outputs the info in the student object
	student& operator =(const student& list); // overloaded assignemnt operator

private:
	string name;
	int numclasses;
	string *classList;
};