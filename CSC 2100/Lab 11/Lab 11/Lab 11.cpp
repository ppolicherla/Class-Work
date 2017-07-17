//Programmed by: Pavan Policherla
//Lab11
// 10/19/2015

#include <iostream>
#include <iomanip>
#include <string>
#include "largeIntegers.h"
using namespace std;

int main()
{
	int array1[22] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9 };
	int array2[30] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9, 8, 8, 8, 5, 4, 3, 2, 1 };

	largeIntegers large(array1, 22);
	large.printNum();
	largeIntegers large2(array2, 30);
	large2.printNum();
	large2.~largeIntegers();
	large2.printNum();
	large2.copyNum(large);
	large2.printNum();


	return 0;
}