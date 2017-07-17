#include"doctorType.h"
#include"personType.h"
#include <iostream>
using namespace std;

int main()
{
	string first;
	string last;
	string special;
	doctorType doc(first, last, special);

	cout << "please enter the first name: ";
	cin >> first;
	cout << "Last name: ";
	cin >> last;
	cout << "Specialty: ";
	cin >> special;

	doc.setName(first, last);
	doc.setSpecialty(special);

	doc.print();
}