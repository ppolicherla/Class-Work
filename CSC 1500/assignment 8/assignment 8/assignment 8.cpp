// Programmed by: Pavan Policherla
// assignment 8]
// 10/27/2015

#include <iostream>
using namespace std;
#include <string>


int main()
{
	char *q;
	q = new char[30];
	string sum = "";
	cout << "enter state machine code: ";
	cin.getline(q, 30);
	enum num{ default, A1, A2, A3, C1, B1, B2 };
	num currentState = default;
	for (int i = 0; i < strlen(q); i++)
	{
		switch (currentState)
		{
		case default:
			if (q[i] == '1')
			{
				currentState = A1;
			}
			else if (q[i] == '8')
			{
				currentState = B1;
			}
			else if (q[i] == '6')
			{
				currentState = C1;
			}
			else
			{
				currentState = default;
				sum = sum + q[i];
			}
			break;
		case A1:
			if (q[i] == '2')
			{
				currentState = A2;
			}
			else if (q[i] == '1')
			{
				currentState = A1;
				sum = sum + "1";
			}
			else if (q[i] == '8')
			{
				currentState = B1;
				sum = sum + "1";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "1";
			}
			else
			{
				currentState = default;
				sum = sum + "1"+ q[i];
			}
			break;

		case A2:
			if (q[i]=='3')
			{
				currentState = A3;
			}
			else if (q[i] == '8')
			{
				currentState = B1;
				sum = sum + "12";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "12";
			}
			else
			{
				currentState = default;
				sum = sum + "12" + q[i];
			}
			break;

		case A3:
			if (q[i]=='4')
			{
				currentState = default;
				sum = sum + "A";	
			}
			else if (q[i] == '8')
			{
				currentState = B1;
				sum = sum + "123";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "123";
			}
			else if (q[i] == '1')
			{
				currentState = A1;
				sum = sum + "123";
			}
			else
			{
				currentState = default;
				sum = sum + "123" + q[i];
			}

			break;

		case B1:
			if (q[i]=='9')
			{
				currentState = B2;
			}
			else if (q[i] == '8')
			{
				currentState = B1;
				sum = sum + "8";
			}
			else if (q[i] == '1')
			{
				currentState = A1;
				sum = sum + "8";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "8";
			}
			else
			{
				currentState = default;
				sum = sum + "8"+ q[i];
			}
			break;

		case B2:
			if (q[i]=='8')
			{
				currentState = default;
				sum = sum + "B";
			}
			else if (q[i] == '1')
			{
				currentState = A1;
				sum = sum + "89";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "89";
			}
			else
			{
				currentState = default;
				sum = sum + "89" + q[i];
			}
			break;

		case C1:
			if (q[i]=='7')
			{
				currentState = default;
				sum = sum + "C";
			}
			else if (q[i] == '6')
			{
				currentState = C1;
				sum = sum + "6";
			}
			else if (q[i] == '1')
			{
				currentState = A1;
				sum = sum + "6";
			}
			else if (q[i] == '8')
			{
				currentState = B1;
				sum = sum + "6";
			}
			else
			{
				currentState = default;
				sum = sum + "6" + q[i];
			}
			break;
		}
	}
	if (currentState == A1)
	{
		sum = sum + "1";
	}
	else if (currentState == A2)
	{
		sum = sum + "12";
	}
	else if (currentState == A3)
	{
		sum = sum + "123";
	}
	else if (currentState == B1)
	{
		sum = sum + "8";
	}
	else if (currentState == B2)
	{
		sum = sum + "89";
	}
	else if (currentState == C1)
	{
		sum = sum + "6";
	}
	
	
	cout << sum << endl;
}
