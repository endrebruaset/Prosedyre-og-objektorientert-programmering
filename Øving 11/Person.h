#pragma once

#include <list>
#include <iostream>
#include <string>

class Person{
private:
	std::string firstName;
	std::string lastName;
public:
	Person(std::string, std::string);
	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }

	bool operator<(const Person&) const;
	bool operator>(const Person&) const;
};

std::ostream& operator<<(std::ostream&, const Person&);

void insertOrdered(std::list<Person>&, const Person&);
