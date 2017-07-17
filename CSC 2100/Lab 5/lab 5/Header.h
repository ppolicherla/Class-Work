class testClass
{
public:

	testClass();
	//Default constructor
	//Initializes the private member variables to 0
	testClass(int a, int b);
	//Constructors with parameters
	//initializes the private member variables to the values
	//specified by the parameters
	//Postcondition:x=a;y=b;
	int sum();
	//Returns the sum of the private member variables
	void print() const;
	//Prints the values of the private member variables

private:
	int x;
	int y;
};
