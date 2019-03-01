#pragma once
#include "Car.h"
#include "Person.h"

enum class Campus {
	Trondheim, Gjøvik, Ålesund
};

ostream& operator<<(ostream& out, const Campus& c);

class Meeting {
public:
	Meeting(int day, int startTime, int endtime, Campus location, string subject, const Person* leader);
	~Meeting();

	int getDay() const { return day; }
	int getStartTime() const { return startTime; }
	int getEndTime() const { return endTime; }
	Campus getLocation() const { return location; }
	string getSubject() const { return subject; }
	const Person* getLeader() const { return leader; }

	void addParticipant(const Person* person);
	vector<string> getParticipantList() const;

	vector<const Person*> findPotentialCoDriving() const;

private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;

	static set<const Meeting*> meetings;
};

ostream& operator<<(ostream& out, const Meeting& m);