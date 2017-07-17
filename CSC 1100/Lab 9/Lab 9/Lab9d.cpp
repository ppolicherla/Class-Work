//Programmed by:Pavan Policherla
//Lab 9 part d
//6/18/2015

#include<iostream>
using namespace std;

int main()
{
	int value;
	int counter = 1;
	bool grade;


	do
	{

		cout << "Please enter a grade to be evaluated: ";
		cin >> value;
		grade = (value < 0 || value > 100);
		if (counter == 5)
		{
			cout << "exceeded maximum number of attempts!!!!!" << endl;
			break;
		}
		else if (grade)
		{
			cout << "the grade entered is invalid!!!!!" << endl;
			counter++;
		}
		else
			break;

	} 
	while (grade);
	
	cout << "the grade is: " << value << endl;

	return 0;

}