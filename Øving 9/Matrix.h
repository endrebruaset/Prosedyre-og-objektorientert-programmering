#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
	double** matrix;
	int M;
	int N;
public:
	Matrix();
	Matrix(int nRows, int nColumns);
	Matrix(const Matrix& rhs);
	explicit Matrix(int nRows);
	~Matrix();

	double get(int row, int col) const;
	void set(int row, int col, double value);

	int getRows() const { return M; }
	int getColumns() const { return N; }

	bool isValid() const;

	double operator()(int row, int col) const;

	Matrix& operator=(Matrix rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix operator+(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix operator-();
};

ostream& operator<<(ostream& os, const Matrix& mat);