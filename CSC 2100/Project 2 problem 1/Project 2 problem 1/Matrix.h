#include<iostream>
using namespace std;


class Matrix 
{
	//public member functions
public:
	Matrix();//default constructor
	Matrix(int rows, int cols);//constructor
	Matrix(const Matrix&m);//copy constructor
	void inputMatrix();//input function
	bool isSimilar(Matrix m1, Matrix m2);//check function
	//overload operator funtions
	Matrix operator+(Matrix &m);
	Matrix operator-(Matrix &m);
	Matrix operator*(Matrix &m);
	friend ostream & operator<<(ostream &out, Matrix &m);
	//destructor
	~Matrix();

	//private member variables
private:
	int **array; 
	int rows, cols;
};