#include "Tile.h"

void Tile::open()
{
	if (state != Cell::flagged) {
		static_cast<Fl_Button*>(pw)->set(); //Setter en button som trykket på, tilsvarer åpnet rute
		state = Cell::open;

		if (isMine) {
			set_label("X");
			set_label_color(Color::dark_red);
		}
	}
}

void Tile::flag()
{
	if (state == Cell::flagged) {
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	}
	else {
		state = Cell::flagged;
		set_label(cellToSymbol.at(Cell::flagged));
		set_label_color(Color::blue);
	}
}

void Tile::reset() {
	static_cast<Fl_Button*>(pw)->clear();
	state = Cell::closed;
	set_label(cellToSymbol.at(Cell::closed));
	isMine = false;
}

void Tile::setAdjMines(int n) {
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
}
