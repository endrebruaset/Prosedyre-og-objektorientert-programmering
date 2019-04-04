#include "Vehicle.h"
#include "Images.h"

void Vehicle::draw() {

	// sjekk om mål er truffet
	checkTargetCollision();

	// sjekk om hindring er truffet og oppdater fysisk tilstand
	checkObstacleCollision();

	if (status == Obstacle::Peel) {
		state.velAcc = 1 - 2 * (state.vel > 0); // kul setning
		state.angAcc = 8;

		state.grip += 0.01*(1 - state.grip);
		state.vel += 0.006 * state.grip * state.velAcc * (std::abs(6 - state.vel) + 5 * ((state.vel > 0) != (state.velAcc > 0)));
		state.angle += 0.03 * state.grip * state.velAcc;
		state.x += state.vel*cos(slideAngle);
		state.y += state.vel*sin(slideAngle);

		if (abs(state.vel) < 0.05) {
			state.angAcc = 0;
			state.velAcc = 0;
			status = Obstacle::None;
		}
	}

	else {
		state.update(myDrive(state, {}, 0));
	}

	// tegn kjøretøyet
	myDraw(state);

	// tegn neste mål
	std::pair<double, double> nextGoal = track.getGoals().at(currentGoal);
	fl_color(FL_DARK_GREEN);
	fl_circle(nextGoal.first, nextGoal.second, goalRad);
}

std::pair<double, double> myDrive(PhysicsState ps,
	const std::vector<std::pair<double, double>>& goals,
	int currentGoal) {

	if (Fl::event_key(FL_Up)) {
		if (ps.velAcc <= 1) { ps.velAcc += 0.5; }
	}
	if (Fl::event_key(FL_Down)) {
		if (ps.velAcc >= -1) { ps.velAcc -= 0.5; }
	}
	if (Fl::event_key(FL_Left)) {
		if (ps.angAcc <= 1) { ps.angAcc += 0.5; }
	}
	if (Fl::event_key(FL_Right)) {
		if (ps.angAcc >= -1) { ps.angAcc -= 0.5; }
	}

	return std::pair<double, double>{ ps.velAcc, ps.angAcc };
}

void myDraw(PhysicsState& ps) {
	if (ps.x > ScreenWidth - vehRad) { ps.x = ScreenWidth - vehRad; }
	if (ps.x < vehRad) { ps.x = vehRad; }
	if (ps.y > ScreenHeight - vehRad) { ps.y = ScreenHeight - vehRad; }
	if (ps.y < vehRad) { ps.y = vehRad; }

	fl_color(FL_RED);
	fl_circle(ps.x, ps.y, vehRad);
	fl_color(FL_BLACK);
	fl_circle(ps.x + vehRad * cos(ps.angle), ps.y + vehRad * sin(ps.angle), 2);
}

void Vehicle::checkTargetCollision() {
	std::pair<double, double> nextGoal = track.getGoals().at(currentGoal);

	if (circleCollision(state.x - nextGoal.first, state.y - nextGoal.second, vehRad + goalRad)) {
		if (currentGoal == numberOfGoals - 1) { currentGoal = 0; }
		else { ++currentGoal; }
	}
}

void Vehicle::checkObstacleCollision() {
	for (auto t : track.getObstacles()) {
		if (circleCollision(state.x - std::get<0>(t), state.y - std::get<1>(t), vehRad + obsRad.at(std::get<Obstacle>(t)))) {
			status = std::get<Obstacle>(t);
			obstacleEffect(status);
		}
	}
}

void Vehicle::obstacleEffect(Obstacle obs) {
	switch (obs) {
	case (Obstacle::Peel):
	{
		if (state.vel > 2) {
			slideAngle = state.angle;
		}
		else {
			status == Obstacle::None;
		}
		break;
	}
	case (Obstacle::Boost):
	{
		state.grip = 2;
		status = Obstacle::None;
		break;
	}
	case (Obstacle::Spill):
	{
		state.grip = 0.5;
		status = Obstacle::None;
		break;
	}
	default:
		break;
	}
}