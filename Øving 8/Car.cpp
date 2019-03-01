#include "Car.h"

Car::Car(int i) {
	freeSeats = i;
}

bool Car::hasFreeSeats() const {
	return bool(freeSeats);
}

void Car::reserveFreeSeat() {
	--freeSeats;
}