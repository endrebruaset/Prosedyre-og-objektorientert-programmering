#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person {
public:
	Person(string name, string email, Car* car = nullptr);

	string getName() const { return name; }
	string getEmail() const { return email; }
	void setEmail(string email);

	bool hasAvailableSeats() const;
	friend ostream& operator<<(ostream& out, const Person& person);
private:
	string name;
	string email;
	Car* car;
};