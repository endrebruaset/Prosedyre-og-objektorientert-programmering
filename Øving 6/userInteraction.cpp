#include "userInteraction.h"

void writeToFile() {
	string word;

	
	try 
	{ 
		ofstream toFile{ "text.txt" }; 

		while (true) {
			cout << "Write a word to \"text.txt\" (enter \"quit\" to exit): ";
			cin >> word;
			if (word == "quit" || word == "Quit") { break; } 
			toFile << word << '\n';
		}
	}

	catch (const exception& e) { cout << "Could not open file, due to error: " << e.what() << endl; }
}

void addLineNumbers() {
	string originalFilename;
	string newFilename;
	string line;
	int lineNumber{ 1 };

	try {
		cout << "What file do you want to add line numbers to?" << endl;
		cin >> originalFilename;
		ifstream originalFile{ originalFilename };
		if (!originalFile) { throw exception("Failed to open file."); }

		cout << "What name do you want your new file to have?" << endl;
		cin >> newFilename;
		ofstream newFile{ newFilename };
		if (!newFile) { throw exception("Failed to open file."); }

		while (getline(originalFile, line)) {
			newFile << to_string(lineNumber) << ": " << line << '\n';
			++lineNumber;
		}

		cout << "Line numbers were added!" << endl;
	}

	catch (const exception& e) { cout << e.what() << endl; }
	}