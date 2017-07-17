//programmed by: Pavan Policherla
// extra credit 2
// 12/8/2015

#include<iostream>
using namespace std;
#include <string>

int main()
{
	char *q;//creating the char pointer
	q = new char[30];//making the pointer a dynamic array
	string sum = "";//initializing the string variable
	cout << "enter a monetary value: ";
	cin.getline(q, 30);
	enum num { IsMoney, State0, State1, State2, State3, State4, State5, State6, State7 };//states
	num currentState = IsMoney;//default state

	for (int i = 0; i < strlen(q); i++)//for loop
	{
		//state machine that tells what to do in each case
		switch (currentState)
		{
		case IsMoney:
			if (q[i] == '$')
			{
				currentState = State0;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State0:
			if (q[i]== '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9' )
			{
				currentState = State1;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State1:
			if (q[i]=='0'||q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9')
			{
				currentState = State2;
			}
			else if (q[i] == ',')
			{
				currentState = State4;
			}
			break;
		case State2:
			if (q[i] == '0' || q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9')
			{
				currentState = State3;
			}
			else if (q[i] == ',')
			{
				currentState = State4;
			}
			break;
		case State3:
			if (q[i] == ',')
			{
				currentState = State4;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State4:
			if (q[i] == '0' || q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9')
			{
				currentState = State5;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State5:
			if (q[i] == '0' || q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9')
			{
				currentState = State6;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State6:
			if (q[i] == '0' || q[i] == '1' || q[i] == '2' || q[i] == '3' || q[i] == '4' || q[i] == '5' || q[i] == '6' || q[i] == '7' || q[i] == '8' || q[i] == '9')
			{
				currentState = State7;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		case State7:
			if (q[i] == ',')
			{
				currentState = State4;
			}
			else
			{
				cout << "Invalid monetary format.";
			}
			break;
		}
		cout << endl << endl;
	}
}