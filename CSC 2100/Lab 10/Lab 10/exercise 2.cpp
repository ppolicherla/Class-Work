//programmed by: Pavan Policherla
// lab10 excersise 2
// 10/14/2015

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int array_size = 10;
	int *a;
	a = new int[array_size];
	int *p = a;
	int i;
	for (i = 0; i < array_size; i++)
	{
		a[i] = i;
	}
	p[0] = 10;
	for (i = 0; i < array_size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}