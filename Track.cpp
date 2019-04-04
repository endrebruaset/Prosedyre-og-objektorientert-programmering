#include "Track.h"
#include "Images.h"

Track::Track() : Fl_Widget{ vehRad, vehRad, w(), h() } {
	for (int i{ 0 }; i < numberOfGoals; ++i) {
		goals.push_back(std::pair<double, double>{rand() % (ScreenWidth - int(goalRad)), rand() % (ScreenHeight - int(goalRad))});
	}

	for (int i{ 0 }; i < numberOfObstacles; ++i) {
		obstacles.push_back(std::tuple<int, int, Obstacle>
			{rand() % (ScreenWidth - int(goalRad)), 
			rand() % (ScreenHeight - int(goalRad)), 
			Obstacle(rand() % 3)});
	}
}

void Track::draw() {
	/*fl_color(FL_BLACK);

	for (auto p : goals) {
		fl_circle(p.first, p.second, goalRad);
	}*/

	for (auto t : obstacles) {
		switch (std::get<Obstacle>(t)) {
		case (Obstacle::Peel):
			drawPeel(std::get<0>(t), std::get<1>(t)); break;
		case (Obstacle::Boost):
			drawBoost(std::get<0>(t), std::get<1>(t)); break;
		case (Obstacle::Spill):
			drawSpill(std::get<0>(t), std::get<1>(t)); break;
		default:
			break;
		}
	}
}

bool circleCollision(double delX, double delY, double sumR) {
	return sumR * sumR >= (delX * delX + delY * delY);
}

std::vector<std::pair<double, double>>& Track::getGoals() const {
	static std::vector<std::pair<double, double>> ref = goals;
	return ref;
}

std::vector<std::tuple<int, int, Obstacle>>& Track::getObstacles() const {
	static std::vector<std::tuple<int, int, Obstacle>> ref = obstacles;
	return ref;
}