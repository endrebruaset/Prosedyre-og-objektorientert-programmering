#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title) : 
	Window{ xy, w, h, title },
	quitBtn{Point{xmax - (buttonW + pad), pad}, buttonW, buttonH, "Quit", cb_quit},

	personName{ Point{fieldPad, pad}, fieldW, fieldH, "Name" },
	personField{ Point{fieldPad, 2 * pad + fieldH}, fieldW, fieldH, "Email" },
	personSeats{ Point{fieldPad, 3 * pad + 2 * fieldH}, fieldW, fieldH, "Seats in car" },
	personNewBtn{ Point{fieldPad, 4 * pad + 3 * fieldH}, buttonW, buttonH, "Add person", cb_new_person },

	meetingSubject{ Point{fieldPad, pad}, fieldW, fieldH, "Subject" },
	meetingDay{ Point{fieldPad, 2 * pad + fieldH}, fieldW, fieldH, "Day" },
	meetingStart{ Point{fieldPad, 3 * pad + 2 * fieldH}, fieldW, fieldH, "Starts at" },
	meetingEnd{ Point{fieldPad, 4 * pad + 3 * fieldH}, fieldW, fieldH, "Ends at" },
	meetingLocation{ Point{fieldPad, 5 * pad + 4 * fieldH}, fieldW, fieldH, "Location" },
	meetingLeader{ Point{fieldPad, 6 * pad + 5 * fieldH}, fieldW, fieldH, "Leader" },

	data{ Point{fieldPad, 7 * pad + 7* fieldH}, fieldW, 6*fieldH, "Data"},
	pageMenu{ Point{xmax - (buttonW + pad), 4*pad}, buttonW, buttonH, Menu::Kind::vertical, "Page"}
{
	pageMenu.attach(new Button{ Point{0, 0}, 0, 0, "Persons", cb_persons });
	pageMenu.attach(new Button{ Point{0, 0}, 0, 0, "Meetings", cb_meetings });
	
	attach(quitBtn);

	attach(personName);
	attach(personField);
	attach(personSeats);
	attach(personNewBtn);

	attach(meetingSubject);
	attach(meetingDay);
	attach(meetingStart);
	attach(meetingEnd);
	attach(meetingLocation);

	meetingLocation.add("Trondheim");
	meetingLocation.add("Ålesund");
	meetingLocation.add("Gjøvik");

	attach(data);
	attach(pageMenu);

	showPersonPage();
}

void MeetingWindow::cb_quit(Address, Address pw) {
	reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::addPerson() {
	if (personSeats.get_int() > 0) { 
		cars.push_back(new Car{ personSeats.get_int() });
		people.push_back(new Person{ personName.get_string(), personField.get_string(), &cars.back() });
		cars.back().reserveFreeSeat();
	}
	else {
		people.push_back(new Person{ personName.get_string(), personField.get_string() });
	}
	
	displayPeople();
}

void MeetingWindow::cb_new_person(Address, Address pw) {
	reference_to<MeetingWindow>(pw).addPerson();
}

void MeetingWindow::printPeople() {
	cout << "The following people were added:" << endl;
	for (Person* p : people) {
		cout << *p << endl;
	}
}

void MeetingWindow::displayPeople() {
	stringstream ss;
	for (Person* p : people) {
		ss << *p;
	}
	data.put(ss.str());
}

void MeetingWindow::showMeetingPage() {
	personName.hide();
	personField.hide();
	personSeats.hide();
	personNewBtn.hide();

	meetingSubject.show();
	meetingDay.show();
	meetingStart.show();
	meetingEnd.show();
	meetingLocation.show();
}

void MeetingWindow::cb_meetings(Address, Address pw) {
	reference_to<MeetingWindow>(pw).showMeetingPage();
}

void MeetingWindow::showPersonPage() {
	displayPeople();

	meetingSubject.hide();
	meetingDay.hide();
	meetingStart.hide();
	meetingEnd.hide();
	meetingLocation.hide();

	personName.show();
	personField.show();
	personSeats.show();
	personNewBtn.show();
}

void MeetingWindow::cb_persons(Address, Address pw) {
	reference_to<MeetingWindow>(pw).showPersonPage();
}