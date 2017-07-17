//Programmed by: Pavan Policherla
//Lab 3 question 2
//05/28/2015

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	double current_salary;
	string name;
	string lastName;
	double percentIncrease;
	double updatedSalary;

	ifstream inFile;
	ofstream outFile;

	inFile.open("Data.txt");
	outFile.open("output.dat");
	outFile << fixed << showpoint << setprecision(2);
	
	inFile >> lastName >> name >> current_salary >> percentIncrease;
	updatedSalary = current_salary*(1 + percentIncrease / 100);
	outFile << name << ' ' << lastName << ' ' << updatedSalary << endl;

	inFile >> lastName >> name >> current_salary >> percentIncrease;
	updatedSalary = current_salary*(1 + percentIncrease / 100);
	outFile << name << ' ' << lastName << ' ' << updatedSalary << endl;

	inFile >> lastName >> name >> current_salary >> percentIncrease;
	updatedSalary = current_salary*(1 + percentIncrease / 100);
	outFile << name << ' ' << lastName << ' ' << updatedSalary << endl;


	return 0;
	
}