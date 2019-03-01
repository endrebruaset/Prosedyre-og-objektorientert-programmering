#include "MeetingWindow.h"
#include "Car.h"
#include "Person.h"
#include "Meeting.h"


int main() {
	setlocale(LC_ALL, "Norwegian");

	constexpr Point topLeft{ 100, 50 };
	constexpr int xmax{ 600 };
	constexpr int ymax{ 400 };
	string title{ "Co-driving" };
	
	MeetingWindow win{ topLeft, xmax, ymax, title };
	gui_main();

	win.printPeople();

	keep_window_open();

	/*int choice{ -1 };
	while (choice != 0) {
		cout << "0: quit" << endl
			<< "1: test Person and Car classes" << endl 
			<< "2: cout << Meeting, and findPotentialCoDrivers()" << endl << endl;

		cin >> choice;
		switch (choice) {
		case 0:
			continue;
		case 1:
		{
			Person endre{ "endre", "endre.bruaset@gmail.com" };
			Car* ptr0{ &Car{ 0 } };
			Person eskil{ "eskil", "eskil.bruaset@gmail.com", ptr0 };
			Car* ptr2{ &Car{ 2 } };
			Person are{ "are", "are.bruaset@sintef.no", ptr2};

			cout << endre << endl;
			cout << eskil << endl;
			cout << are << endl;
		}
		case 2:
		{
			Person endre{"Endre", "endre.bruaset@gmail.com"};
			Meeting meet{ 2, 14, 16, Campus::Gjøvik, "Matte 1", &endre };
			Person eskil{ "Eskil", "eskil.bruaset@gmail.com", &Car{2} };
			meet.addParticipant(&eskil);
			cout << meet << endl;

			Person nora{ "Nora", "nora@gmail.com", &Car{0} };
			Person pula{ "Pula", "pula@pula.pule", &Car{7} };
			Meeting eskilsmeeting{ 2,14,15, Campus::Gjøvik, "C++", &nora };
			eskilsmeeting.addParticipant(&pula);
			vector<const Person*> coDrivers{ eskilsmeeting.findPotentialCoDriving() };

			cout << "Potenital co-drivers:" << endl;
			for (const Person* p : coDrivers) {
				cout << '\t' << p->getName() << endl;
			}
		}
		default:
			break;
		}
	}*/
}

