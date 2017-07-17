#include<iostream> 
using namespace std;
#include "Matrix.h"


int main()
{
	//creation of matrix objects
	Matrix m1(2, 2); 
	Matrix m2(2, 2);
	m1.inputMatrix(); 
	m2.inputMatrix();
	Matrix m3(2, 2); 
	Matrix m4(2, 2); 
	Matrix m5(2, 2);
	//comparison to make sure that operations can be preformed on the matricies
	if (m3.isSimilar(m1, m2)) 
	{
		m3 = m1 + m2;
		m4 = m1 - m2;
		m5 = m1*m2;
		

	}
	else 
	{
		cout << "\nRows & cols of 2 matrices are different ";
		return 0;
	}
	//output
	cout << "Addition of 2 matrices is ";
	cout << m3;
	cout << "Subtraction of 2 matrices is ";
	cout << m4;
	cout << "Multiplication of 2 matricies is ";
	cout << m5;
	Matrix m6(m5);
	cout << "The copied matrix is ";
	cout << m6;
	return 0;
}
