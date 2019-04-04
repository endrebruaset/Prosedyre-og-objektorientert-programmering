#pragma once

#include "utilities.h"

class Track : public Fl_Widget {
private:
	std::vector<std::pair<double, double>> goals;
	std::vector<std::tuple<int, int, Obstacle>> obstacles;
public:
	Track();
	void draw() override;

	std::vector<std::pair<double, double>>& getGoals() const;
	std::vector<std::tuple<int, int, Obstacle>>& getObstacles() const;
};

bool circleCollision(double delX, double delY, double sumR);