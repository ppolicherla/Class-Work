//Programmed by: Pavan Policherla
//Lab 3 question 1
//6/4/2015

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;

	string name;//stores the first name of the employee
	string lastName;//stores the last name of the employee
	string department;//department he works in 
	double salary;//monthly gross salary
	double bonus;//bonus as a percent
	double tax;//tax in percent
	double paycheck;//paycheck total
	double distance;//distance traveled
	double travel_time;//time taken to travel given distance
	double speed;//average speed traveled
	int sold; //number of coffee cups sold
	double cost; //cost per cup
	double sales;//total sales amount made


	inFile.open("inData.txt");
	outFile.open("outData.txt");

	outFile << fixed << showpoint << setprecision(2);

	inFile >> name >> lastName >> department >> salary >> bonus >> tax;
	paycheck = (salary*(1 + bonus / 100));
	paycheck = paycheck - (paycheck*(tax / 100));
	outFile << "Name: " << name <<' ' << lastName << ", " << "Department: " << department << endl << "Monthly Gross Salary: $" << salary << ", " << "Monthly Bonus: " << bonus << "%, " << "Taxes: " << tax << '%' << endl << "Paycheck: $" << paycheck << endl;

	inFile >> distance >> travel_time;
	speed = distance / travel_time;
	outFile << endl << "Distance Traveled: " << distance << " miles, " << "Traveling Time: " << travel_time << " hours" << endl << "Average Speed: " << speed << " miles per hour" << endl;

	inFile >> sold >> cost;
	sales = sold*cost;
	outFile << endl << "Number of Coffee Cups Sold: " << sold << ", " << "Cost: " << cost << " per cup" << endl << "Sales Amount: $" << sales << endl;

	inFile.close();
	outFile.close();
	return 0;
}