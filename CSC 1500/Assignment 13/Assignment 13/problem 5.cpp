#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void matrixMult(int arr1[][10], int arr2[][10], int arr3[][10], int m, int n, int q);

int main()
{

	int arr1[10][10], arr2[10][10], arr4[10][10], m, n, p, q, i, j, k;
	cout << "Enter rows and columns of matrix a: ";
	cin >> m >> n;
	cout << "Enter rows and columns of matrix b: ";
	cin >> p >> q;


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
	}
	matrixMult(arr1, arr2, arr4, m, n, q);
}

void matrixMult(int arr1[][10], int arr2[][10], int arr3[][10], int m, int n, int q)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			arr3[i][j] = 0;
			for (int k = 0; k < n; ++k)

				arr3[i][j] = arr3[i][j] + (arr1[i][k] * arr2[k][j]);
			cout << arr3[i][j] << " ";

		}
		cout << endl;
	}
}