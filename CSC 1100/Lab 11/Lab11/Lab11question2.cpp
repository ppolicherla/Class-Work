//Programmed by: Pavan Policherla
//Lab11 question 2
//6/29/2015
#include<iostream>
#include<iomanip>
using namespace std;
//below are the defined functions prototypes that will be used to complete the program
void getPrices(double& current, double& priceOneYAgo, double& priceTwoYAgo);
void calculateInflation(double current, double priceOneYAgo, double priceTwoYAgo, double& infCurrentY, double& infOneYAgo);
void printResult(double infCurrentY, double infOneYAgo);
//the main function
int main()
{
	//variables to be used in functions
	double current, infCurrentY,  infOneYAgo, priceOneYAgo, priceTwoYAgo;
	//function calls to complete the program
	getPrices(current, priceOneYAgo, priceTwoYAgo);
	calculateInflation(current, priceOneYAgo, priceTwoYAgo, infCurrentY, infOneYAgo);
	printResult(infCurrentY, infOneYAgo);
	return 0;
}

//definition of the get prices function, will as the user to input the information to be used in inflation calculations
void getPrices(double& current, double& priceOneYAgo, double& priceTwoYAgo)
{
	//asks for the current price of the item
	cout << "Please enter the current price of the item: ";
	cin >> current;
	//asks for the price of the item a year ago.
	cout << "Please enter the price of the item a year ago: ";
	cin >> priceOneYAgo;
	//asks for the price of the item two years ago.
	cout << "Please enter the price of the item two years ago: ";
	cin >> priceTwoYAgo;
}

//definition of the calculate inflation function, calculates inflation based ont the prices inputed by the user
void calculateInflation(double current, double priceOneYAgo, double priceTwoYAgo, double& infCurrentY, double& infOneYAgo)
{
	//makes sure that the resulting double values do not exceed two decimal places
	cout << fixed << showpoint << setprecision(2);
	//equations to find the values of the inflation in the current year and the inflation one year ago
	infCurrentY = (current-priceOneYAgo) / priceOneYAgo;
	infOneYAgo = (priceOneYAgo-priceTwoYAgo) / priceTwoYAgo;
}
//definition that will print out the results, based on the results of the calculate inflation function
void printResult(double infCurrentY, double infOneYAgo)
{
	//variable to help determine whether on not the inflation is increasing, decreasing or hasn't changed
	double inflation;
	//outputs the inflation values of the current year and the year before.
	cout << "the inflation currently is: " << infCurrentY << endl;
	cout << "the inflation a year ago is:" << infOneYAgo << endl;
	//equation to determine the value of the inflation variable.
	inflation = infCurrentY - infOneYAgo;
	//if loop to help the program decide whether or not to report if the inflation increased, decreased or stayed the same.
	if (inflation > 0)
		cout << "The Inflation is increasing!" << endl;
	else if (inflation == 0)
		cout << "the inflation has not changed.......meh" << endl;
	else
		cout << "the inflation has decreased......YAY!" << endl;
}