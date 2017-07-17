#include <iostream> 
using namespace std;

class Date
{
	// data declaration section
private:
	int month;
	int day;
	int year;

	// method declarations
public:
	Date(int mm, int dd, int yyyy);   // constructor
	int operator==(Date &);  // declare the operator== function
	int operator>=(Date &);
	int operator<=(Date &);
};