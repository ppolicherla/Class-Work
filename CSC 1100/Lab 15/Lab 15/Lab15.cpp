//Programmed By: Pavan Policherla
//Lab 15
//7/9/2015
#include<iostream>

using namespace std;
//prototype for the grade function that will fill the array with the grades
const int ROWS=6;//constant for the rows of the 2d array
const int COLS=5;//constant for the coloumns in the 2d array
void grade(char tests[ROWS][COLS], int grades[]);//function header

//main function
int main()
{
	//the 2d array that holds all the test answers for the 6 tests
	char tests[6][5] = { { 'T', 'F', 'T', 'T', 'T' }, { 'T', 'T', 'T', 'T', 'T' }, { 'T', 'T', 'F', 'F', 'T' }, { 'F', 'T', 'F', 'F', 'F' }, { 'F', 'F', 'F', 'F', 'F' }, { 'T', 'T', 'F', 'T', 'F' } };
	int grades[6];//the grades array that will be populated
	grade(tests, grades);//function call
	//for loop to print out the array
	for (int i = 0; i < 6; i++)
	{
		cout << grades[i] << " ";
	}
	cout << endl;
	return 0;
}
//function definition
void grade(char tests[ROWS][COLS], int grades[])
{
	char ans[5] = { 'T', 'T', 'F', 'F', 'T' };//array that works as the answer key for the test
	int grade;//variable that will hold the total score of the arrays
	for (int i = 0; i < 6; i++)//for loop that will traverse the rows of the 2D array
	{
		grade = 0;//initialization of the grade variable
		for (int j = 0; j < 5; j++)//for loop so the program will read all the answers of the array
		{
			if (tests[i][j] == ans[j])//if statement that will check if the answer given matches the answer in the answer key
				grade = grade + 5;    //and will award 5 points for the correct answer.
		
		}
		grades[i] = grade;//statment that will populate the grades array
	}
}