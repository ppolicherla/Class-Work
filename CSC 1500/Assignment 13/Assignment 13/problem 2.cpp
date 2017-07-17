
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void hammingCode(int arra[7]);
void errorMaker(int arra[7]);
int check(int array[7]);
int convert(int check1, int check2, int check3);
int fix(int address, int array[7]);
void translate(int array[7]);

int main()
{
	int decimal, error;
	cout << "Please enter a decimal number to be sent: ";
	cin >> decimal;
	int binArray[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int i = 0;
	while (decimal > 1)
	{
		binArray[i] = decimal % 2;
		decimal = decimal / 2;
		i += 1;
	}
	binArray[i] = decimal;
	int fixedArray[7] = { 0,0,0,0,0,0,0 };
	for (int j = 0; j < 7; j++)
	{
		fixedArray[6 - j] = binArray[j];
	}
	fixedArray[2] = fixedArray[3];
	fixedArray[3] = 0;
	hammingCode(fixedArray);
	errorMaker(fixedArray);
	cout << endl << "hamming code with an error: ";

	for (int i = 0; i < 7; i++)
	{
		cout << fixedArray[i];
	}
	cout << endl;
	error = check(fixedArray);
	fix(error, fixedArray);
	cout << endl << "The hamming after fixing the error is: ";
	for (int i = 0; i < 7; i++)
	{
		cout << fixedArray[i];
	}
	cout << endl;

	translate(fixedArray);

	cout << endl;
}

void hammingCode(int arra[])
{
	arra[0] = (arra[2] + arra[4] + arra[6]) % 2;
	arra[1] = (arra[2] + arra[5] + arra[6]) % 2;
	arra[3] = (arra[4] + arra[5] + arra[6]) % 2;
}

void errorMaker(int arra[7])
{
	int num;
	cout << endl << "pick a bit to have an error inserted, or 00 for no error: ";
	cin >> num;
	if (arra[num - 1] == 0)
	{
		arra[num - 1] = 1;
	}
	else if (arra[num - 1] == 1)
	{
		arra[num - 1] = 0;
	}
	else if (num == 00)
	{
		arra[num - 1] = arra[num - 1];
	}
}

int check(int array[7])
{
	int check1, check2, check3;

	check1 = (array[0] + array[2] + array[4] + array[6]) % 2;
	check2 = (array[1] + array[2] + array[5] + array[6]) % 2;
	check3 = (array[3] + array[4] + array[5] + array[6]) % 2;
	return convert(check1, check2, check3);
}
int convert(int check1, int check2, int check3)
{
	int convert[3] = { check3, check2, check1 };

	int decimal = 0;
	for (int b = 2; b >= 0; b--)
	{
		decimal = decimal + (convert[b] * pow(2, 2 - b));
	}

	return decimal;
}
int fix(int address, int array[7])
{
	if (address > 0)
	{
		if (array[address - 1] == 0)
		{
			array[address - 1] = 1;
		}
		else if (array[address - 1] == 1)
		{
			array[address - 1] = 0;
		}
	}
	return 0;
}


void translate(int array[7])
{
	int trans[4];
	trans[0] = array[2];
	trans[1] = array[4];
	trans[2] = array[5];
	trans[3] = array[6];

	int decimal = 0;
	for (int b = 3; b >= 0; b--)
	{
		decimal = decimal + (trans[b] * pow(2, 3 - b));
	}
	cout << endl << "The original decimal message is: " << decimal << endl;
}