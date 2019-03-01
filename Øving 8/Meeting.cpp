#include "Meeting.h"

ostream& operator<<(ostream& out, const Campus& c) {
	if (c == Campus::Trondheim) { out << "Trondheim"; }
	else if (c == Campus::Gjøvik) { out << "Gjøvik"; }
	else if (c == Campus::Ålesund) { out << "Ålesund"; }

	return out;
}

Meeting::Meeting(int d, int sTime, int eTime, Campus loc, string sub, const Person* p) :
	day{d}, startTime{sTime}, endTime{eTime}, location{loc}, subject{sub}, leader{p}
{
	addParticipant(leader);
	meetings.insert(this);
}

Meeting::~Meeting() {
	meetings.erase(this);
}

void Meeting::addParticipant(const Person* person) {
	participants.insert(person);
}

set<const Meeting*> Meeting::meetings;

vector<string> Meeting::getParticipantList() const {
	vector<string> names;

	for (const Person* p : participants) {
		names.push_back(p->getName());
	}

	return names;
}

 ostream& operator<<(ostream& out, const Meeting& m) {
	 out << "The meeting has the following specifications:" << '\n'
		 << "Location: " << m.getLocation() << '\n'
		 << "Subject: " << m.getSubject() << '\n'
		 << "Starts at: " << to_string(m.getStartTime()) << '\n'
		 << "Ends at: " << to_string(m.getEndTime()) << '\n'
		 << "Leader's name: " << m.getLeader()->getName() << '\n'
		 << "Participants: " << '\n';

	 for (const string& name : m.getParticipantList()) {
		 out << '\t' << name << '\n';
	 }
	 
	 return out;
}

 vector<const Person*> Meeting::findPotentialCoDriving() const {
	 vector<const Person*> potentialCoDrivers;

	 for (const Meeting* otherMeeting : meetings) {
		 if (this != otherMeeting &&	// the two meetings do not have the same pointer adresses
			 otherMeeting->getLocation() == location &&
			 otherMeeting->getDay() == day &&
			 abs(otherMeeting->getStartTime() - startTime) <= 1 &&
			 abs(otherMeeting->getEndTime() - endTime) <= 1) 
		 {
			 for (const Person* p : otherMeeting->participants) {
				 if (p->hasAvailableSeats()) { potentialCoDrivers.push_back(p); }
			 }
		 }
	 }

	 return potentialCoDrivers;
 }