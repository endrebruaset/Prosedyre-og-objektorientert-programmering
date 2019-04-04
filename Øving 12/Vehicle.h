#pragma once

#include "utilities.h"
#include "Track.h"

class Vehicle : public Fl_Widget {
private:
	PhysicsState state;
	drivingAlgorithm* steering;

	const Track& track;

	int currentGoal{ 0 };

	Obstacle status = Obstacle::None;
public:
	Vehicle(double x, double y, double angle, drivingAlgorithm* algorithm, Track& track) : 
		Fl_Widget{ vehRad, vehRad, w(), h() }, 
		state{ x,y,angle }, 
		steering{ algorithm }, 
		track{ track } {}
	void draw() override;

	void checkTargetCollision();
	void checkObstacleCollision();

	void obstacleEffect(Obstacle);
	double slideAngle = 0;
};

drivingAlgorithm myDrive;
drawingAlgorithm myDraw;