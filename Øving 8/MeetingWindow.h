#pragma once

#include "Graph.h"
#include "Simple_window.h"
#include "Meeting.h"
#include "Graph_lib.h"
using namespace Graph_lib;

class MeetingWindow : public Window {
public:
	MeetingWindow(Point xy, int w, int h, const string& title);

	void printPeople();
private:
	// Person
	Button quitBtn;
	static void cb_quit(Address, Address pw);

	Button personNewBtn;
	static void cb_new_person(Address, Address pw);
	void addPerson();

	In_box personName;
	In_box personField;
	In_box personSeats;

	Multiline_out_box data;
	void displayPeople();

	Vector_ref<Person> people;
	Vector_ref<Car> cars;

	void showPersonPage();
	static void cb_persons(Address, Address pw);

	// Meeting
	Menu pageMenu;

	In_box meetingSubject; 
	In_box meetingDay;
	In_box meetingStart;
	In_box meetingEnd;

	Choice meetingLocation;
	Choice meetingLeader;

	void showMeetingPage();
	static void cb_meetings(Address, Address pw);

	// Window constants
	static constexpr int xmax{ 600 };
	static constexpr int ymax{ 400 };
	static constexpr int pad{ ymax / 30 };
	static constexpr int buttonH{ ymax / 18 };
	static constexpr int buttonW{ xmax / 5 };
	static constexpr int fieldH{ ymax / 18 };
	static constexpr int fieldW{ xmax / 2 };
	static constexpr int fieldPad{ xmax / 7 };
};