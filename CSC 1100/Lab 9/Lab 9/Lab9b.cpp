//Programmed by:Pavan Policherla
//Lab 9 part b
//6/18/2015

#include<iostream>
using namespace std;

int main()
{
	int value;
	bool grade;

	do
	{

		cout << "Please enter a grade to be evaluated: ";
		cin >> value;
		grade = (value < 0 || value > 100);
		if (grade)
		{
			cout << "the grade entered is invalid!!!!!" << endl;
		}
		else
			break;

	} 
	while (grade);

	cout << "the grade is: " << value << endl;

	return 0;

}