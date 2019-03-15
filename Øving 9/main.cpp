#include "Utilities.h"
#include "Matrix.h"
#include "DummyTest.h"

int main() {

	int choice{ -1 };
	while (choice != 0) {
		cout << "0: quit" << endl
			<< "1: fillInFibonacciNumbers() and print()" << endl 
			<< "2: createFibonacci()" << endl 
			<< "3: Matrix" << endl 
			<< "4: dummyTest()" << endl 
			<< "5: kopikonstruktør og tilordningsoperator" << endl 
			<< "6: addisjon av matriser" << endl 
			<< "7: subtraksjon av matriser" << endl << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			continue;
		case 1:
		{
			const int length{ 10 };
			int result[length];
			fillInFibonacciNumbers(result, length);
			printArray(result, length);

			cout << endl << endl;
			break;
		}
		case 2:
		{
			createFibonacci();
			cout << endl << endl;
			break;
		}
		case 3:
		{
			Matrix matrix1;
			Matrix matrix2{ 2, 3 };
			Matrix matrix3{ 3 };

			cout << "Matrix 1" << endl << matrix1 << endl << endl;
			cout << "Matrix 2" << endl << matrix2 << endl;
			cout << "Matrix 3" << endl << matrix3 << endl;

			cout << "Set matrix2[2][3] to 14" << endl;
			matrix2.set(2, 3, 14);

			cout << "Matrix 2" << endl << matrix2 << endl;

			cout << "Value in matrix3[1][1]: " << matrix3.get(1, 1) << endl << endl;
			break;
		}
		case 4:
		{
			dummyTest();
			cout << endl;
			break;
		}
		case 5:
		{
			Matrix matrix1{ 2, 3 };
			matrix1.set(1, 1, 11);
			Matrix matrix2{};
			Matrix matrix3{ matrix1 };
			Matrix matrix4;
			matrix4 = matrix1;
			matrix4.set(1, 2, 4);
			matrix3.set(1, 2, 6);

			cout << "Matrix 1" << endl << matrix1 << endl;
			cout << "Matrix 2" << endl << matrix2 << endl << endl;
			cout << "Matrix 3" << endl << matrix3 << endl;
			cout << "Matrix 4" << endl << matrix4 << endl << endl;
			break;
		}
		case 6:
		{
			Matrix A{ 2,2 };
			A.set(1, 1, 1); A.set(1, 2, 2); A.set(2, 1, 3); A.set(2, 2, 4);
			Matrix B{ 2,2 };
			B.set(1, 1, 4); B.set(1, 2, 3); B.set(2, 1, 2); B.set(2, 2, 1);
			Matrix C{ 2,2 };
			C.set(1, 1, 1); C.set(1, 2, 3); C.set(2, 1, 1.5); C.set(2, 2, 2);

			cout << "A:" << endl << A << endl;
			cout << "B:" << endl << B << endl;
			cout << "C:" << endl << C << endl;
			cout << "A += (B + C):" << endl << (A += (B + C)) << endl;
			cout << "B:" << endl << B << endl;
			cout << "C:" << endl << C << endl;
			break;
		}
		case 7:
		{
			Matrix A{ 2,2 };
			A.set(1, 1, 1); A.set(1, 2, 2); A.set(2, 1, 3); A.set(2, 2, 4);
			Matrix B{ 2,2 };
			B.set(1, 1, 4); B.set(1, 2, 3); B.set(2, 1, 2); B.set(2, 2, 1);
			Matrix C{ 2,2 };
			C.set(1, 1, 1); C.set(1, 2, 3); C.set(2, 1, 1.5); C.set(2, 2, 2);

			cout << "A:" << endl << A << endl;
			cout << "B:" << endl << B << endl;
			cout << "C:" << endl << C << endl;
			cout << "A - B:" << endl << (A - B) << endl;
			cout << "A -= (B + C):" << endl << (A -= (B + C)) << endl;
			cout << "B:" << endl << B << endl;
			cout << "C:" << endl << C << endl;
			cout << "-C" << endl << -C << endl;
			cout << "C:" << endl << C << endl;
			break;
		}
		default:
			break;
		}
	}

	return 0;
}