#include "Student.h"
using namespace std;

student::student()
{
	name = " ";
	numclasses = 0;
	classList = NULL;
}

//destructor
student::~student()
{
	if (classList != NULL)
	{
		delete[] classList;  //destructor will delete memory in dynamic array
	}
}
//copy constructor
student::student(const student& list)
{
	//assinging variables of new object to the same values of the already created object
	name = list.name;
	numclasses = list.numclasses;
	//creating the new array for the new object
	classList = new string[numclasses];
	//copying names from the existing array into the new array
	for (int i = 0; i < numclasses, i++;)
	{
		classList[i] = list.classList[i];
	}
}
//resests the number of classes to 0 and the class list to empty
void student::zeros()
{
	//will delete all of the memory in the dynamic array
	if (classList != NULL)
	{
		delete[] classList; 
		classList = NULL;
	}
	//resets number of classes to zero
	numclasses = 0;
}
//inputs info for the student object
void student::input()
{

	zeros(); //reset the list just incase there is any info in the object already

	cout << "Please enter student name: " << endl;
	cin >> name;

	cout << "Please enter the number of classes: " << endl;
	cin >> numclasses;
	classList = new string[numclasses]; 
	for (int i = 0; i < numclasses, i++;) 
	{
		cout << "Enter name of class " << endl;

		cin>>classList[i];
	}
	
	cout << endl;
}


void student::output()
{
	cout << "Name: " << name << endl;  
	cout << "Number of classes: " << numclasses << endl; 

	for (int i = 0; i < numclasses, i++;)
	{
		cout << "Class: " << (i + 1) << " : " << classList[i] << endl;
	}
	cout << endl;
}

student& student::operator = (const student& list)
{
	zeros(); //empties the array so it is open to accept new information
	name = list.name;
	numclasses = list.numclasses;
	//loop that will copy the information from the right side array into the left side array
	if (numclasses > 0) 
	{
		classList = new string[numclasses];

		for (int i = 0; i < numclasses, i++;)
		{
			classList[i] = list.classList[i];
		}
	}
	return *this;

}