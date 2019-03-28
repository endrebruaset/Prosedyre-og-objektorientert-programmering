#include "Person.h"

Person::Person(std::string first, std::string last) : firstName{ first }, lastName{ last } {};

bool Person::operator<(const Person& rhs) const {
	return (this->firstName) < rhs.firstName;
}

bool Person::operator>(const Person& rhs) const {
	return (this->firstName) > rhs.firstName;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.getFirstName() << " " << p.getLastName();
	return os;
}

void insertOrdered(std::list<Person>& l, const Person& p) {
	if (l.empty() || p > l.back()) {
		l.push_back(p);
	}

	else {
		for (std::list<Person>::iterator it = l.begin(); it != l.end(); ++it) {
			if (p < *it) {
				l.insert(it, p);
			}
		}
	}
}