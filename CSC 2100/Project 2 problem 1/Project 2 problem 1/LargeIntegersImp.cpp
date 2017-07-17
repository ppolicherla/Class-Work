#include "LargeIntegers.h"
using namespace std;
//output function
void largeIntegers::output()
{
	//loops through the array to ouput the values
	for (int i = length - 1; i >= 0; i--)
	{
		cout << large[i];
	}
}
//input functions
void largeIntegers::input()
{
	//variable to represent the number inputted
	string in;
	cout << "Please enter a large number no bigger than " << DIGITS << " digits: ";
	cin >> in;
	int i;
	//loop to define the actual length of the number
	for ( i = 0; in[i] != '\0'; i++)
	{
		length = i;
	}
	int k = 0;
	//entering the values into the array 
	for (int j = i - 1; j >= 0; j--)
	{
		large[j] = in[k++] - 48;
	}
}
//default constructor
largeIntegers::largeIntegers()
{
	//loop that will initialize all values in the array to 0
	for (int i = 0; i < DIGITS; i++)
	{
		large[i] = 0;
		length = DIGITS - 1;//setting the length to the maximum length -1
	}
}
//overload comparison operator
int largeIntegers::operator==(const largeIntegers& comp)
{
	int i;
	//checks if the length is similar
	if (length < comp.length)
	{
		return -1;
	}
	if (comp.length < length)
	{
		return 1;
	}
	//checks the values to see which is larger
	for (int i = length - 1; i >= 0; i--)
	{
		if (large[i] < comp.large[i])
		{
			return -1;
		}
		else if (comp.large[i] < large[i])
		{
			return 1;
		}
		return 0;
	}
}
//overload addition operator
largeIntegers largeIntegers::operator+(const largeIntegers& comp)
{
	//create a temporary large integer
	largeIntegers temp;
	//variable the represents the carry action in addition
	int carry = 0;
	int c, i;
	//checks to see which integer length to use
	if (length > comp.length)
	{
		c = length;
	}
	else
	{
		c = comp.length;
	}
	//performing the addition and augmenting the values so that no single index is greater than 9
	for (i = 0; i < c; i++)
	{
		temp.large[i] = large[i] + comp.large[i] + carry;
	}
	if (temp.large[i] > 9)
	{
		temp.large[i] %= 10;
		carry = 1;
	}
	else
	{
		carry = 0;
	}
	//using the carry to influence the next value
	if (carry == 1)
	{
		temp.length = c + 1;

		if (temp.length >= DIGITS)
		{
			cout << "ERROR! ERROR! ERROR!";
		}
		else
		{
			temp.large[i] = carry;
		}
	}
	else
	{
		temp.length = c;
	}
	return temp;
}
//overload subtraction operator
largeIntegers largeIntegers:: operator-(const largeIntegers& comp)
{
	//create a temporary large integer
	largeIntegers temp;
	int c;
	//checks to see which integer length to use
	if (length > comp.length)
	{
		c = length;
	}
	else
	{
		c = comp.length;
	}
	int borrow = 0;//variable that will represent the borrow value from the next value
	//loop to preform subtraction
	for (int i = c; i >= 0; i--)
	{
		//determining whether we borrowed from the previous term
		if (borrow == 0)
		{
			if (large[i] >= comp.large[i])
			{
				temp.large[i] = large[i] - comp.large[i];
			}
			else
			{
				borrow = 1;
				temp.large[i] = (large[i] + 10) - comp.large[i];
			}
		}
	}
	temp.length = c;
	return temp;
}
//overload multiplication operator
largeIntegers largeIntegers::operator*(const largeIntegers& comp)
{
	//creating integer objects and variables to be used
	largeIntegers temp;
	int i, j, k, tmp, m = 0;
	//starting at the last digit of the bottom list
	for (i = 0; i < comp.length; i++)
	{
		k = 1;
		//going through and multiplying each term in the left matrix by the first term in the right matrix
		for (j = 0; j < length; j++)
		{
			tmp = large[j] * comp.large[i];
			temp.large[k] = temp.large[k] + tmp;
			temp.large[k + 1] = temp.large[k + 1] + temp.large[k / 10];
			k++;
			if (k > m)
			{
				m = k;
			}
		}
	}
	//readjusting the length of the new array
	temp.length = m;
	if (temp.length > DIGITS)
	{
		cout << "ERROR! ERROR! ERROR!";
	}
	return temp;
}