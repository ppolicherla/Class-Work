#include "doctorType.h"
#include "personType.h"
#include<iostream>
using namespace std;

void doctorType::print() const
{
	
	cout <<"First Name: "<< personType::getFirstName() << " Last Name: " << personType::getLastName() <<" Specialty: " << getSpecialty() << endl;
}

string doctorType::getFirstName()
{
	return personType::getFirstName();
}
string doctorType::getLastName()
{
	return personType::getLastName();
}
string doctorType::getSpecialty() const
{
	return specialty;
}
void doctorType::setName(string first, string last)
{
	personType::setName(first, last);
}
void doctorType::setSpecialty(string special)
{
	specialty = special;
}
doctorType::doctorType(string first, string last, string special)
	:personType(first = "", last = "")
{
	specialty = special;
}