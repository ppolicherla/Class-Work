//Programmed by: Pavan Policherla
//Lab 02 exercise 2
//9/16/2015

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
void input(double array1[4][3], ifstream& infile);
double saleAmount(double array2[4][3], double tickets, double cost);
double ticketsold(double tickets);
void output(double array3[4][3], double& sum, double& tsum);
int main()
{
	ifstream infile;
	infile.open("sample.txt");
	double numbers[4][3], sum, tsum;
	input(numbers, infile);
	output(numbers, sum, tsum);

}

void input(double array1[4][3], ifstream& infile)
{
	cout << showpoint << fixed << setprecision(2) << endl;
	for (int i = 0; i < 4; i++)
	{
		infile >> array1[i][0];
		infile >> array1[i][1];
	}
}

double saleAmount(double tickets, double cost)
{
	double totalSales;
	totalSales = (cost*tickets);	
	return totalSales;
}

double ticketsold(double tickets)
{
	double ticketTotal;
	ticketTotal = tickets;
	return ticketTotal;
}
void output(double array3[4][3	], double& sum, double& tsum)
{
	sum = 0;
	tsum = 0;
	double ticketotal = 0;
	double saletotal = 0;
	double tickets, cost;
	for (int i = 0; i < 4; i++)
	{
		cost = array3[i][0];
		tickets = array3[i][1];
		sum = saleAmount(tickets, cost);
		tsum = ticketsold(tickets);
		ticketotal = ticketotal + tsum;
		saletotal = saletotal + sum;
	}
	cout << "Total tickets sold: " << ticketotal<< endl;
	cout << "Total sale amount: " << saletotal << endl;
}
