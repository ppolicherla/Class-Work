//programmed by: Pavan Policherla
//Lab 3
//9/21/2015

#include<iostream>
#include<cmath>
using namespace std;
int x1, x2, x3, x4, x5;
double mean(int x1, int x2, int x3, int x4, int x5);
double standDev(int x1, int x2, int x3, int x4, int x5);
int input();
int main()
{
	input();
	cout << "The mean is : " << mean(x1, x2, x3, x4, x5) << endl;

	cout << "The standard deviation is: " << standDev(x1, x2, x3, x4, x5) << endl;	
}

int input()
{
	cout << "Please enter in 5 numbers to be used in the calculation: ";
	cin >> x1 >> x2 >> x3 >> x4 >> x5;
	return x1, x2, x3, x4, x5;
}

double mean(int x1, int x2, int x3, int x4, int x5)
{
	double mean;
	mean = (x1 + x2 + x3 + x4 + x5) / 5;
	return mean;
}

double standDev(int x1, int x2, int x3, int x4, int x5)
{
	double standDev;
	standDev = sqrt((pow((x1 - mean(x1, x2, x3, x4, x5)), 2) + pow((x2 - mean(x1, x2, x3, x4, x5)), 2) + pow((x3 - mean(x1, x2, x3, x4, x5)), 2) + pow((x4 - mean(x1, x2, x3, x4, x5)), 2) + pow((x5 - mean(x1, x2, x3, x4, x5)), 2)) / 5);
	return standDev;
}


