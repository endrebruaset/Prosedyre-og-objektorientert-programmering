#include "Emoji.h"

void Face::attach_to(Graph_lib::Window& win) {
	win.attach(face);
}

Face::Face(Point& center, int radius) : face{ center, radius } { 
	face.set_fill_color(Color::yellow); 
	face.set_color(Color::black);
}

EmptyFace::EmptyFace(Point& center, int radius) : 
	Face{ center, radius }, 
	rightEye{ Point{center.x + static_cast<int>(radius / 2.7), center.y - radius / 3}, static_cast<int>(radius / 4.5) },
	leftEye{ Point{center.x - static_cast<int>(radius / 2.7), center.y - radius / 3}, static_cast<int>(radius / 4.5) }
{	
	rightEye.set_fill_color(Color::black);
	rightEye.set_color(Color::black);
	leftEye.set_fill_color(Color::black);
	leftEye.set_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(rightEye);
	win.attach(leftEye);
}

SmilingFace::SmilingFace(Point& center, int radius) :
	EmptyFace(center, radius),
	mouth{ center, radius, radius , 190, 350 }
{
	mouth.set_color(Color::black);
}

void SmilingFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

SadFace::SadFace(Point& center, int radius) : 
	EmptyFace(center, radius),
	mouth{ Point{center.x, center.y + radius / 2}, radius, radius , 10, 170 }
{
	mouth.set_color(Color::black);
}


void SadFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

WinkingFace::WinkingFace(Point& center, int radius) :
	Face{ center, radius },
	openEye{ Point{center.x + static_cast<int>(radius / 2.7), center.y - radius / 3}, static_cast<int>(radius / 4.5) },
	openEyePupil{ Point{center.x + static_cast<int>(radius / 2.7), center.y - radius / 3}, radius / 12 },
	mouth{ {center.x, center.y + radius / 4}, radius / 2, radius / 4 },
	tounge{ {center.x, center.y + static_cast<int>(radius / 2.4)}, radius / 4, radius / 3 },
	winkingEye{}
{
	winkingEye.add({ center.x - static_cast<int>(radius / 2), center.y - static_cast<int>(radius / 2.3) });
	winkingEye.add({ center.x - static_cast<int>(radius / 6), center.y - radius / 3 });
	winkingEye.add({ center.x - static_cast<int>(radius / 2), center.y - static_cast<int>(radius / 3.8) });

	openEye.set_color(Color::black);
	openEye.set_fill_color(Color::white);
	openEyePupil.set_color(Color::black);
	openEyePupil.set_fill_color(Color::black);
	mouth.set_fill_color(Color::dark_yellow);
	mouth.set_color(Color::black);
	tounge.set_fill_color(Color::dark_red);
	tounge.set_color(Color::black);
	winkingEye.set_color(Color::black);
}

void WinkingFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(openEye);
	win.attach(openEyePupil);
	win.attach(winkingEye);

	win.attach(mouth);
	win.attach(tounge);
}

ConcernedFace::ConcernedFace(Point& center, int radius) :
	EmptyFace(center, radius),
	rightEyebrow{ Point{center.x + static_cast<int>(radius / 2.7), center.y - static_cast<int>(radius / 1.35)},
				static_cast<int>(radius / 2.5), radius / 4, 210, 330 },
	leftEyebrow{ Point{center.x - static_cast<int>(radius / 2.7), center.y - static_cast<int>(radius / 1.45)},
				static_cast<int>(radius / 2.5), radius / 4, 30, 150 },
	mouth{ {center.x - radius / 2, center.y + radius / 4}, {center.x + radius / 2, center.y + radius / 5}}
{
	rightEyebrow.set_color(Color::black);
	leftEyebrow.set_color(Color::black);
	mouth.set_color(Color::black);
}

void ConcernedFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(rightEyebrow);
	win.attach(leftEyebrow);
	win.attach(mouth);
}

RollingEyesFace::RollingEyesFace(Point& center, int radius) :
	Face(center, radius),
	rightEye{ Point{center.x + static_cast<int>(radius / 2.7), center.y - radius / 3}, static_cast<int>(radius / 4.5) },
	leftEye{ Point{center.x - static_cast<int>(radius / 2.7), center.y - radius / 3}, static_cast<int>(radius / 4.5) },
	rightPupil{ Point{center.x + static_cast<int>(radius / 2.7), center.y - static_cast<int>(radius / 2.5)}, radius / 12 },
	leftPupil{ Point{center.x - static_cast<int>(radius / 2.7), center.y - static_cast<int>(radius / 2.5)}, radius / 12 },
	mouth{ {center.x, center.y + radius / 4}, radius / 4, radius / 3 }
{
	rightEye.set_color(Color::black);
	rightEye.set_fill_color(Color::white);
	leftEye.set_color(Color::black);
	leftEye.set_fill_color(Color::white);
	rightPupil.set_color(Color::black);
	rightPupil.set_fill_color(Color::black);
	leftPupil.set_color(Color::black);
	leftPupil.set_fill_color(Color::black);
	mouth.set_color(Color::black);
	mouth.set_fill_color(Color::dark_yellow);
}

void RollingEyesFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(rightEye);
	win.attach(leftEye);
	win.attach(rightPupil);
	win.attach(leftPupil);
	win.attach(mouth);
}