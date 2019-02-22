// Example program in TDT4102_Graphics template, from PPP page 415
#include "userInteraction.h"
#include "fileOperations.h"
#include "courseCatalog.h"
#include "temps.h"

int main() {
	int choice{ -1 };
	while (choice != 0) {
		cout << "0: quit" << endl
			<< "1: writeToFile()" << endl 
			<< "2: addLinenumbers()" << endl
			<< "3: countCharacters()" << endl
			<< "4: testCourseCatalog()" << endl 
			<< "5: readTemperatures()" << endl 
			<< "6: plotTempetratures()" << endl << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			continue;
		case 1:
			writeToFile();
			break;
		case 2:
			addLineNumbers();
			break;
		case 3:
			countCharacters("grunnlov.txt");
			cout << endl;
			break;
		case 4:
		{
			testCourseCatalog();
			cout << endl;
			break;
		}
		case 5:
		{
			vector<Temps> temperatures{ readTemperatures("temperatures.txt") };
			for (Temps temp : temperatures) {
				cout << temp.max << '\t' << temp.min << endl;
			}
			cout << endl;
			break;
		}
		case 6:
		{
			plotTemperatures();
			break;
		}
		default:
			cout << "Invalid input, try again." << endl << endl;
			break;
		}
	}
}

