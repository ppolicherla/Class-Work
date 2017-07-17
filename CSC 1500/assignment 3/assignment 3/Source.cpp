//programmed by: Pavan Policherla
//assignment 3
//9/15/2015

#include<iostream>
using namespace std;
void convertToBinary(int num);
void convertToDecimal(int num);
void binaryAdd(int num1, int num2);
void binaryAddConv(int num1, int num2);
int main()
{
	int num, num1, num2, choice;
	cout << "What kind of operation would you like to preform?" << endl;
	cout << "Convert decimal to binary enter 0" << endl;
	cout << "Convert binary to decimal enter 1" << endl;
	cout << "Binary addition enter 2" << endl;
	cout << "Binary addition then convert to decimal enter 3" << endl;
	cin >> choice;

	if (choice == 0)
	{
		cout << "Please enter a positive number to be converted: ";
		cin >> num;

		if (num < 0)
			{
				cout << "INVALID!!!!!!!!";
				cin >> num;
			}
		else
			{
				cout << endl << num << " = ";
				convertToBinary(num);
				cout << endl << endl;
			}
	}
	else if (choice == 1)
	{
		cout << "Please enter a binary to be converted to decimal: ";
		cin >> num;
		convertToDecimal(num);
	}

	else if (choice == 2)
	{
		cout << "Enter the first binary: ";
		cin >> num1;
		cout << endl << "Enter the second binary: ";
		cin >> num2;
		cout << endl;

		binaryAdd(num1, num2);
	}

	else if (choice == 3)
	{
		cout << "Enter the first binary: ";
		cin >> num1;
		cout << endl << "Enter the second binary: ";
		cin >> num2;
		cout << endl;
		binaryAddConv(num1, num2);

		
	}


}

void convertToBinary(int num)
{


	int num2;

	num = num / 2;
	num2 = num % 2;

	if (num >0)
	{
		convertToBinary(num);
	}
	cout << num2;

}

void convertToDecimal(int num)
{
	int r, base=1, dec=0, hold=num;
	while (num > 0)
	{
		r = num % 10;
		dec = dec + r * base;
		base = base * 2;
		num = num / 10;
	}
	cout << hold << " = " << dec << endl;
}

void binaryAdd(int num1, int num2)
{
	int binaryTotal;
	int array[6] = { 0, 0, 0, 0, 0, 0 };
	int i = 5;
	int previousBinary = 0;
	binaryTotal = num1 + num2;
	
	while (binaryTotal)
	{
		previousBinary = binaryTotal;
		binaryTotal = binaryTotal / 10;
		array[i--] = previousBinary - (binaryTotal * 10);
	}
	for (int a = 0; a < 6; a++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (array[j] == 2)
			{
				array[j] = 0;
				array[j - 1] += 1;
			}
		}
	}
	for (int k = 0; k < 6; k++)
	{
		cout << array[k];
	}

	cout << endl;

}

void binaryAddConv(int num1, int num2)
{
	int binaryTotal, decimal=0;
	int array[6] = { 0, 0, 0, 0, 0, 0 };
	int i = 5;
	int previousBinary = 0;
	binaryTotal = num1 + num2;

	while (binaryTotal)
	{
		previousBinary = binaryTotal;
		binaryTotal = binaryTotal / 10;
		array[i--] = previousBinary - (binaryTotal * 10);
	}
	for (int a = 0; a < 6; a++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (array[j] == 2)
			{
				array[j] = 0;
				array[j - 1] += 1;
			}
		}
	}

	for (int b = 0; b < 6; b++)
	{
		decimal = decimal + array[b];
		decimal = decimal * 10;
	}
	convertToDecimal(decimal);
}