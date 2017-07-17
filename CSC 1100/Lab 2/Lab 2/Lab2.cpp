//Programmed by: Pavan Policherla
//Lab2
// 5/26/2015
#include <iostream>
using namespace std;

int main()
{
	double length, width, depth;
	double perimeter, volume, surface;
	double lxw, lplusw;
	cout << "what is the length of the pool? ";
	cin >> length;
	cout << endl << "what is the width of the pool? ";
	cin >> width;
	cout << endl << "what is the average depth of the pool? ";
	cin >> depth;
	lxw = length*width;
	lplusw = length + width;
	perimeter = 2 * lplusw;
	volume = lxw*depth;
	surface = perimeter*depth + lxw;
	cout << endl << endl << "the perimeter of the of the pool is " << perimeter;
	cout << endl << "the volume of the pool is " << volume;
	cout << endl << "the underground surface are of the pool is " << surface << endl;
	return 0;
}