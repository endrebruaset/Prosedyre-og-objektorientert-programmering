#pragma once

// Når programmet kjører vil det skrives ut
//		a: 4
//		b: 4
//		c: 4
//		a: 5
//		b: 5
//		c: 5
// fordi variablene peker til samme minneadresse.

// Programmet krasjer på slutten av programmet fordi destruktørene til a, b og c kalles, 
// men fordi de peker til samme minneadresse prøver programmet å slette noe som ikke finnes.

class Dummy {
public:
	int *num;
	Dummy() { 
		num = new int{ 0 }; 
	}

	Dummy(const Dummy& rhs) {
		this->num = new int;
		*(this->num) = *rhs.num;
	}

	~Dummy() { delete num; }

	Dummy& operator=(const Dummy& rhs) {
		delete this->num;
		this->num = new int;
		*(this->num) = *rhs.num;
		return *this;
	}
};void dummyTest();


