#include <iostream>
using namespace std;

class lineType
{
	//Overload the stream insertion and extraction operators
	friend ostream& operator<<(ostream&, const lineType&);
	friend istream& operator>>(istream&, lineType&);

public:

	void setLine(double a = 0, double b = 0, double c = 0);
	//Function to set the line.

	bool operator+() const;
	//Returns true if this line is vertical; false otherwise.
	bool operator-() const;
	//Returns true if this line is horizontal; false otherwise.

	bool operator==(const lineType& otherLine) const;
	//Returns true if both lines are the same.

	bool operator||(const lineType& otherLine) const;
	//Returns true if this line is parallel to otherLine.


	lineType(double a = 0, double b = 0, double c = 0);
	//Constructor

private:
	double xCoeff;
	double yCoeff;
	double constTerm;
};