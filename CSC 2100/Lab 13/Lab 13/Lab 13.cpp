// Programmed by: Pavan Policherla
// Lab 13
// 10/26/2015

#include<iostream>
#include "date.h"
using namespace std;

int main()
{
	int mm1=8, mm2=7, mm3=12;
	int dd1 = 12, dd2 = 10, dd3 = 25;
	int yyyy1 = 2017, yyyy2 = 2018, yyyy3 = 2017;
	Date date1(mm1, dd1, yyyy1);
	Date date2(mm2, dd2, yyyy2);
	Date date3(mm3, dd3, yyyy3);

	date2.operator<=(date1);
	date3.operator>=(date1);

}