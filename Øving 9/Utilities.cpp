#include "Utilities.h"

void fillInFibonacciNumbers(int result[], int length) {
	result[0] = 0;
	result[1] = 1;

	for (int i{ 2 }; i < length; ++i) {
		result[i] = result[i - 1] + result[i - 2];
	}
}

void printArray(int arr[], int length) {
	for (int i{ 0 }; i < length; ++i) {
		cout << arr[i] << " ";
	}
}

void createFibonacci() {
	int length;
	cout << "How many numbers of the Fibonacci sequence do you want to generate?" << endl;

	cin >> length;
	while (!cin || length < 0) {
		cout << "Invalid input, must be a positive integer. Try again:" << endl;
		if (!cin) {
			cin.clear(); cin.ignore(80, '\n');
		}
		cin >> length;
	}
	
	int* fibonacci = new int[length];

	fillInFibonacciNumbers(fibonacci, length);
	printArray(fibonacci, length);

	delete[] fibonacci;
}