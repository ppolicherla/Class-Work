//programmed by: Pavan Policherla
//Programming project question1
//7/16/2015

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
//function prototypes
int f(int level, int problemType);
void correct();
void incorrect();
void percentage();
void result(int right, int wrong);
//main function 
int main()
{
	int respond, answer = 0, right = 0, wrong = 0, counter = 0;
	int level1, problem;
	cout << "What level would you like to attempt? ";
	cin >> level1;
	cout << endl << "What type of problem would you like to practice? ";
	cout << endl << "1 is multiplication";
	cout << endl << "2 is addition";
	cout << endl << "3 is division";
	cout << endl << "4 is subtraction";
	cout << endl << "5 is mixed problems";
	cout << endl;
	cin >> problem;
	while (answer!=-1)
	{
			answer = f(level1, problem);
			cin >> respond;
			if (respond == answer)
			{
				correct();
				right++;
				counter++;
				//cout << right << " " << counter;    test to see if incrementation works

			}
			else
			{
				while (respond != answer && counter<10)
				{
					incorrect();
					wrong++;
					counter++;
					//cout << wrong << " " << counter;           test to see if incrementation works
					cin >> respond;
				}
			}
			if (counter == 10)
			{
				answer = -1;
				result(right, wrong);
				cout << "Good Bye" << endl;
			}
			

	
	}
	return 0;
}


//function to generate the problems the student must solve
int f(int level, int problemType)
{
	//generates the numbers for the problems
	srand(time(0));
	int v1 = rand() % static_cast<int>(pow(10, level));
	int v2 = rand() % static_cast<int>(pow(10, level));
	//statement to randomize the problems if student enters 5
	if (problemType = 5)
	{
		srand(time(0));
		problemType = (rand() % 4) + 1;
	}
	switch (problemType)
		{
		case 1:

			cout << "What is " << v1 << "*" << v2 << "?" << endl;
			return v1*v2;
			break;

		case 2:
			cout << "What is " << v1 << "+" << v2 << "?" << endl;
			return v1 + v2;
			break;

		case 3:

			cout << "What is " << v1 << "/" << v2 << "?" << endl;
			return v1 / v2;
			break;

		case 4:
			cout << "What is " << v1 << "-" << v2 << "?" << endl;
			return v1 - v2;
			break;
		}
	

}
//function that will output the incorrect statement
void incorrect()
{
	int ranNum = (rand() % 4) + 1;
	switch (ranNum)
	{
	case 1:
		cout << "Please try again" << endl << endl;
		break;
	case 2:
		cout << "Try once more" << endl << endl;
		break;
	case 3:
		cout << "Don't give up!" << endl << endl;
		break;
	case 4:
		cout << "Keep trying" << endl << endl;
		break;
	}
}
//function that will output the correct statement
void correct()
{
	int ranNum = (rand() % 4) + 1;
	switch (ranNum)
	{
	case 1:
		cout << "Very good!" << endl << endl;
		break;
	case 2:
		cout << "Excellent!" << endl << endl;
		break;
	case 3:
		cout << "Nice work!" << endl << endl;
		break;
	case 4:
		cout << "Keep up the good work!" << endl << endl;
		break;
	}

}
//function that will calculate the results of the student based on the answers given
void result(int right, int wrong)
{
	if (right/(right+wrong) < 0.75)
		cout << "Please ask your teacher for extra help" << endl;
	else
		cout << "Congratulations, you are ready to go to the next level!" << endl;
	right = 0;
	wrong = 0;
}
