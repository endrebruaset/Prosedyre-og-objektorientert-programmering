#pragma once
#include "GUI.h"

using namespace Graph_lib;

// De forskjellige tilstandene en Tile kan være i
enum class Cell { closed, open, flagged };

// For å sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For å sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };


struct Tile : Button
{
	Tile(Point pos, int size, Graph_lib::Callback cb, bool mine = false)
		: Button(pos, size, size, "", cb), isMine{ mine } {};

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw(); }

	void open(); // Åpner ruten
	void flag(); // Flagger en rute

	void reset(); // Resetter ruten

	void setAdjMines(int n);

	Cell state = Cell::closed;

	bool isMine;
};