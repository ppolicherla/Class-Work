//programmed by: Pavan Policherla
// assignment 11
//11/21/2015

#include<iostream>
using namespace std;

void matrixMult(int arr1[][10], int arr2[][10], int arr3[][10], int m, int n, int q);
void matrixMultInt(int arr1[][10], int mult, int row, int col);


int main()
{

	int arr1[10][10], arr2[10][10], arr3[10][10], arr4[10][10], m, n, p, q, i, j, k, f, h;
	cout << "Enter rows and columns of matrix a: ";
	cin >> m >> n;
	cout << "Enter rows and columns of matrix b: ";
	cin >> p >> q;
	cout << "Enter rows and columns of matrix c: ";
	cin >> f >> h;

	if (n == p)
	{
		cout << "enter first matrix a: ";
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cin >> arr1[i][j];
			}
		}

		cout << "enter second matrix b: " << endl;
		for (i = 0; i < p; ++i)
		{
			for (j = 0; j < q; ++j)
			{
				cin >> arr2[i][j];
			}
		}

		cout << "enter second matrix c: " << endl;
		for (i = 0; i < f; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cin >> arr3[i][j];
			}
		}
	}
	switch (1)
	{
		int input;
	case 1:
		cout << "enter 1 for multiplying matrix a by matrix b: " << endl;
		cout << "enter 2 for multiplying matrix b by matrix a: " << endl;
		cout << "enter 3 for multiplying matrix c by matrix b: " << endl;
		cout << "enter 4 to multiply matrix a by 2" << endl;
		cout << "enter 5 to multiply matrix b by -3" << endl;
		cin >> input;
		switch (input)
		{
		case 1: matrixMult(arr1, arr2, arr4, m, n, q);
			break;
		case 2: matrixMult(arr2, arr1, arr4, n, p, q);
			break;
		case 3: matrixMult(arr3, arr2, arr4, f, h, q);
			break;
		case 4: matrixMultInt(arr1, 2 , 2, 2);
			break;
		case 5: matrixMultInt(arr2, -3, 2, 2);
			break;
		}
	}
}

void matrixMult(int arr1[][10], int arr2[][10], int arr3[][10], int m, int n, int q)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			arr3[i][j] = 0;
			for (int k = 0; k < n; ++k)

				arr3[i][j] = arr3[i][j]+ (arr1[i][k] * arr2[k][j]);
			cout << arr3[i][j] << " ";

		}
		cout << endl;
	}
}


void matrixMultInt(int arr1[][10], int mult, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr1[i][j] = arr1[i][j] * mult;
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
}


