#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include <iostream>
#include <chrono>
#include <thread>

#include "Vehicle.h"
#include "Track.h"
#include "Images.h"

int main() {

	srand(time(NULL));

	auto win = std::make_unique<Fl_Double_Window>( 1000, 600, "Window" );
	win->color(FL_WHITE);

	Track* track = new Track{};
	Vehicle* vehicle = new Vehicle{ 0, 0, 0, {}, *track };

	win->end();
	win->show();

	auto next = std::chrono::steady_clock::now();
	while (win->shown()) {

		std::this_thread::sleep_until(next);
		next += std::chrono::microseconds(1000000 / 60);

		Fl::check();
		Fl::redraw();
	}
	
	return 0;
}

