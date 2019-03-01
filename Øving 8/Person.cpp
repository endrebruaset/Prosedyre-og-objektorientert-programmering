#pragma once
#include "Person.h"

Person::Person(string n, string e, Car* c) : name{ n }, email{ e }, car{ c } {}

void Person::setEmail(string e) { email = e; }

bool Person::hasAvailableSeats() const {
	if (car) { 
		if (car->hasFreeSeats()) { return true; } 
		else { return false; }
	}
	else { return false; }
}

// Bør deklarere overlastingen med const parameter for å forsikre oss om at person-parameteren ikke forandres.
// Kan ikke bruke const dersom funksjonen faktsik skal gjøre endringer, for eksempel å sette nye verdier til medlemsvariable.

ostream& operator<<(ostream& out, const Person& person) {
	out << "Name: " << person.name << '\n';
	out << "Email: " << person.email << '\n';
	if (person.car) { 
		if (person.hasAvailableSeats()) { out << "Car: " << "has a car with free seats" << '\n'; }
		else { out << "Car: " << "has a car, but no free seats" << '\n'; }
	}
	else { out << "Car: " << "does not have a car" << '\n'; }

	return out;
}