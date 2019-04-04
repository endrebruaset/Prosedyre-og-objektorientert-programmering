#pragma once

#include <cmath>
#include <vector>
#include <utility>
#include <random>
#include <iostream>
#include <tuple>
#include <map>

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <FL/Fl_JPEG_Image.H>

constexpr double vehRad{ 15 };
constexpr double goalRad{ 30 };
constexpr double spillRad{ 20 };
constexpr double boostRad{ 10 };
constexpr double peelRad{ 5 };

constexpr int numberOfGoals{ 10 };
constexpr int numberOfObstacles{ 10 };

constexpr int ScreenHeight = 600;
constexpr int ScreenWidth = 1000;

struct PhysicsState {
	double x, y, angle, vel, grip = 1;
	double angAcc = 0;
	double velAcc = 0;
	PhysicsState(double x, double y, double angle) : x{ x }, y{ y }, angle{ angle } {}

	void update(std::pair<double, double> accel) {
		grip += 0.01*(1 - grip);
		vel += 0.006 * grip * accel.first * (std::abs(6 - vel) + 5 * ((vel > 0) != (accel.first > 0)));
		angle += 0.03 * grip * accel.second;
		x += vel * cos(angle); y += vel * sin(angle);
	}
};

using drivingAlgorithm = std::pair<double, double>(PhysicsState ps,
	const std::vector<std::pair<double, double>>& goals,
	int currentGoal);

using drawingAlgorithm = void(PhysicsState& ps);

enum class Obstacle {
	Spill, Boost, Peel, None
};

static const std::map<Obstacle, double> obsRad{
	{Obstacle::Peel, peelRad},
	{Obstacle::Boost, boostRad},
	{Obstacle::Spill, spillRad},
	{Obstacle::None, 0}
};