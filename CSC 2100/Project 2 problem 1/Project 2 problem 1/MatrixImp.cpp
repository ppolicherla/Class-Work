#include "Matrix.h"
//default constructor
Matrix::Matrix()
{
	//initializing the values to 0 or empty
	array = NULL; 
	rows = cols = 0;
}
//constructor with values
Matrix:: Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	//creating the new 2d dynamic array
	array = new int *[rows]; 
	//creating the colums of the array
	for (int i = 0; i<rows; i++)
		array[i] = new int[cols]; 
}
//copy constructor
Matrix::Matrix(const Matrix& m)
{
	//setting the rows and columns values to the second matrix values
	rows = m.rows;
	cols = m.cols;
	//creating the new array rows
	array= new int *[rows];
	//creating the colums
	for (int i = 0; i < m.rows; i++)
	{
		array[i] = new int[m.cols];
	}
	//populating the indecies
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = m.array[i][j];
		}
	}
}
//input for the matrix to change values
void Matrix:: inputMatrix()
{
	cout << "Enter " << rows << "x" << cols << " elements :";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
	}
}

//checking both matricies to see if matrix operations can be performed
bool Matrix:: isSimilar(Matrix m1, Matrix m2)
{
	if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//overload function for addition
Matrix Matrix:: operator+(Matrix &m) 
{
	Matrix c(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			c.array[i][j] = array[i][j] + m.array[i][j];
		}
	}
	return c;
}
//overload function for subtraction
Matrix Matrix:: operator-(Matrix &m) 
{
	Matrix c(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			c.array[i][j] = array[i][j] - m.array[i][j];
		}
	}
	return c;
}
//overload function for multiplication
Matrix Matrix :: operator*(Matrix &m)
{
	Matrix c(rows, cols);
	

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				c.array[i][j] = 0;
			}
			cout << endl;
		}

		for (int i = 0; i < rows; ++i)

			for (int j = 0; j < cols; ++j)
			{
				c.array[i][j] = 0;
				for (int k = 0; k < cols; ++k)
					c.array[i][j] += array[i][k] * m.array[k][j];
			}

	
	return c;
}
//overload function for output
ostream & operator<<(ostream &out, Matrix &m) 
{
	out << endl;
	for (int i = 0; i<m.rows; i++)
	{
		for (int j = 0; j<m.cols; j++)
			out << "\t" << m.array[i][j];
		out << endl;
	}
	return out;
}
//destructor
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete array[i];
	}
	delete array;
}