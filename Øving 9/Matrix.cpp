#include "Matrix.h"
#include <utility>
#include <iomanip>
using namespace std;

Matrix::Matrix() : M{ 0 }, N{ 0 }, matrix{ nullptr } {}

Matrix::Matrix(int nRows, int nColumns) : M{ nRows }, N{ nColumns } {
	matrix = new double*[M];

	for (int i{ 0 }; i < M; ++i) {
		matrix[i] = new double[N];

		for (int j{ 0 }; j < N; ++j) {
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int nRows) : Matrix{ nRows, nRows } {
	for (int i{ 0 }; i < M; ++i) {
		matrix[i][i] = 1;
	}
}

Matrix::~Matrix() {
	for (int i{ 0 }; i < M; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = nullptr;
}

double Matrix::get(int row, int col) const {
	return matrix[row - 1][col - 1];
}

void Matrix::set(int row, int col, double value) {
	matrix[row - 1][col - 1] = value;
}

double Matrix::operator()(int row, int col) const { return matrix[row][col]; }

bool Matrix::isValid() const {
	return (matrix != nullptr);
}

ostream& operator<<(ostream& os, const Matrix& mat) {
	if (mat.isValid()) {
		for (int i{ 0 }; i < mat.getRows(); ++i) {
			for (int j{ 0 }; j < mat.getColumns(); ++j) {
				os << setw(3) << mat(i, j) << " ";
			}
			os << '\n';
		}
	}

	else {
		os << "The matrix is invalid";
	}

	return os;
}

Matrix::Matrix(const Matrix& rhs) : Matrix{rhs.M, rhs.N} {
	if (rhs.isValid()) {
		for (int i{ 0 }; i < M; ++i) {
			for (int j{ 0 }; j < N; ++j) {
				this->matrix[i][j] = rhs.matrix[i][j];
			}
		}
	}

	else {
		this->matrix = nullptr;
	}
}

Matrix& Matrix::operator=(Matrix rhs) {
	swap(this->matrix, rhs.matrix);
	swap(this->M, rhs.M);
	swap(this->N, rhs.N);
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
	if (M != rhs.M || N != rhs.N) {
		this->matrix = nullptr;
	}

	else {
		for (int i{ 0 }; i < M; ++i) {
			for (int j{ 0 }; j < N; ++j) {
				this->matrix[i][j] += rhs.matrix[i][j];
			}
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& rhs) {
	if (M != rhs.M || N != rhs.N) {
		Matrix result{};
		return result;
	}

	else {
		Matrix result{ *this };
		result += rhs;
		return result;
	}
}

Matrix& Matrix::operator-=(const Matrix& rhs) {
	if (M != rhs.M || N != rhs.N) {
		this->matrix = nullptr;
	}

	else {
		for (int i{ 0 }; i < M; ++i) {
			for (int j{ 0 }; j < N; ++j) {
				this->matrix[i][j] -= rhs.matrix[i][j];
			}
		}
	}

	return *this;
}

Matrix Matrix::operator-(const Matrix& rhs) {
	if (M != rhs.M || N != rhs.N) {
		Matrix result{};
		return result;
	}

	else {
		Matrix result{ *this };
		result -= rhs;
		return result;
	}
}

Matrix Matrix::operator-() {
	Matrix result{ *this };
	
	for (int i{ 0 }; i < M; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			result.matrix[i][j] = -this->matrix[i][j];
		}
	}

	return result;
}