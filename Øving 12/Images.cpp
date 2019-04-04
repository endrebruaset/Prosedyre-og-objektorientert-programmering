#include "Images.h"

void drawPeel(int x, int y) {
	Fl_JPEG_Image peel{ "Sprites/peelSprite.jpeg" };
	peel.draw(x, y);
}


void drawBoost(int x, int y) {
	Fl_JPEG_Image boost{ "Sprites/boostSprite.jpeg" };
	boost.draw(x, y);
}

void drawSpill(int x, int y) {
	Fl_JPEG_Image spill{ "Sprites/spillSprite.jpeg" };
	spill.draw(x, y);
}
