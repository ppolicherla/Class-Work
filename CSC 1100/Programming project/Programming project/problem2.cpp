//programmed by: Pavan Policherla
//Programming project question1
//7/16/2015

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
//prototypes of all of the functions used in the program
double weeklyPay(double hours, double salary);
void input(string array1[10], double numbers1[10][3],ifstream& file1);
void output(string array2[10], double numbers2[10][3], double& sum);
void outputAverage(string array3[10], double numbers3[10][3], double& sum);

//main function
int main()
{
	//variables
	ifstream inFile;
	inFile.open("problem2data.txt");
	string names[10];
	double numbers[10][3], sum;
	//function calls
	input(names, numbers, inFile);
	output(names, numbers, sum);
	cout << endl;
	outputAverage(names, numbers, sum);

	inFile.close();
}
//function to input data from the txt file into the arrays
void input(string array1[10], double numbers1[10][3], ifstream& file1)
{
	cout << showpoint << fixed << setprecision(2) << endl;
	for (int i = 0; i < 10; i++)
	{
		file1 >> array1[i];
		file1 >> numbers1[i][0];
		file1 >> numbers1[i][1];
		
	}
}
//function to calculate the pay that each employee recieves
double weeklyPay(double hours, double salary)
{
	cout << showpoint << fixed << setprecision(2) << endl;
	double pay1, pay2, payTotal;

	if (hours > 40)
	{
		pay1 = 40 * salary;
		hours = hours - 40;
		pay2 = hours*1.5*salary;
		payTotal = pay1 + pay2;
	}
	else
	{
		payTotal = hours*salary;
	}
	return payTotal;
}
//function to output the contents of the arrays
void output(string array2[10], double numbers2[10][3], double& sum)
{
	sum = 0;
	double total = 0;
	double salary, hours;
	//loop that will add the employee's total salary and add it to the array
	for (int i = 0; i<10; i++)
	{
		hours = numbers2[i][0];
		salary = numbers2[i][1];
		sum = weeklyPay(hours, salary);
		numbers2[i][2] = sum;
		total = total + sum;
	}
	sum = total / 10;
	//loop to output the information
	cout << "Name\t" << "Hours worked\t" << "Salary\t" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array2[i] << "\t" << numbers2[i][0] << "\t" << numbers2[i][1] << "\t" << numbers2[i][2] << endl;
	}
	cout << endl << "Average Salary:  $" << sum << endl;
}
//function that will output the employees whose salary is greater than the average
void outputAverage(string array3[10], double numbers3[10][3], double& sum)
{
	cout << "Enployees whose salaries are greater than or equal to the average salary." << endl;
	for (int i = 0; i < 10; i++)
	{
		if (numbers3[i][2] >= sum)
			cout << array3[i] << ", ";
	}
	cout << endl;
}