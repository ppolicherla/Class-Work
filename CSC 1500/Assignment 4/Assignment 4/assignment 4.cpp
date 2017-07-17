//programmed by: Pavan Policherla
//assignment 4
//9/22/2015

#include<iostream>
#include<cmath>
using namespace std;

int baconbits(int array[]);
int babybackbits(int crunchy1, int greasy2, int chewy3);
int cook(int bacon, int oink[]);
void baconToPig(int array[]);
int main()
{
	int binary, bacon;
	cout << "Please enter a binary number to be analyzed: ";
	cin >> binary;
	cout << endl;
	
	int oink[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int i = 6;
	int newbinary = 0;
	
	while (binary)
	{
		newbinary = binary;
		binary = binary / 10;
		oink[i--] = newbinary - (binary * 10);
	}

	bacon = baconbits(oink);
	cook(bacon, oink);
	baconToPig(oink);


}

int baconbits(int array[])
{
	int crunchy1, greasy2, chewy3;

	crunchy1 = (array[0] + array[2] + array[4] + array[6]) % 2;  //check quadrant I
	greasy2 = (array[1] + array[2] + array[5] + array[6]) % 2;   //check quadrant II
	chewy3 = (array[3] + array[4] + array[5] + array[6]) % 2;    //check quadrant III
	return babybackbits(crunchy1, greasy2, chewy3);
	
}

int babybackbits(int crunchy1, int greasy2, int chewy3)
{
	int babybackbit[3] = { chewy3, greasy2, crunchy1};

	for (int i = 0; i < 3; i++)
	{
		cout << babybackbit[i];
	}
	cout << endl;
	int decimal=0;
	for (int b = 2; b >=0; b--)
	{
		decimal = decimal+(babybackbit[b] * pow(2, 2 - b));
	}
	cout << decimal;
	return decimal;

}

int cook(int bacon, int oink[])
{
	if (bacon > 0)
	{
		if (oink[bacon - 1] == 0)
		{
			oink[bacon - 1] = 1;
		}
		else if (oink[bacon-1]==1)
		{
			oink[bacon - 1] = 0;
		}
	}

	cout << endl << endl << "the correct binary is: ";
	for (int i = 0; i < 7; i++)
	{
		cout << oink[i];
	}
	cout << endl;
	return 0;
}

void baconToPig(int array[])
{
	int pig[4];
	pig[0] = array[2];
	pig[1] = array[4];
	pig[2] = array[5];
	pig[3] = array[6];

	int decimal = 0;
	for (int b = 2; b >= 0; b--)
	{
		decimal = decimal + (pig[b] * pow(2, 2 - b));
	}
	cout << endl << "The original decimal message is: " << decimal;

	cout << endl << "Enjoy all your pig code!!!!!" << endl;
}