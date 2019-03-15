#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, (height*cellSize + infoHeight), title), width(width), height(height), mines(mines),
	quit{ Point{static_cast<int>(1.9*buttonW), info_y}, buttonW, buttonH, "Quit", cb_quit },
	restart{ Point{static_cast<int>(2.9*buttonW), info_y}, buttonW, buttonH, "Restart", cb_restart },
	minesLeft{ Point{static_cast<int>(0.65*buttonW), info_y}, fieldW, buttonH, "Mines" },
	labelCover{ Point{0,info_y}, Point{static_cast<int>(0.65*buttonW), info_y + infoHeight} }
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i * cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner på tilfeldige posisjoner
	for (int i{ 0 }; i < mines; ++i) {
		int random{ rand() % (width * height) };

		while (tiles[random].isMine) {
			random -= 1;
			if (random == 0) { random = width * height - 1; }
		}

		tiles[random].isMine = true;
	}

	// Legg til knapper og felter
	attach(quit); quit.hide();
	attach(restart); restart.hide();
	attach(minesLeft); minesLeft.put(to_string(mines));
	attach(labelCover);

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int mineCount{ 0 };

	for (Point xy : coords) {
		if (this->at(xy).isMine) { mineCount += 1; }
	}

	return mineCount;
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (this->at(xy).state == Cell::closed) {
		this->at(xy).open();
		++openedTiles;

		if (!this->at(xy).isMine) {
			int mines{ countMines(adjacentPoints(xy)) }; // number of mines on adjacent tiles

			if (mines > 0) {
				this->at(xy).set_label(to_string(mines));
				this->at(xy).set_label_color(minesToColor.at(mines));
			}

			else if (mines == 0) {
				for (Point p : adjacentPoints(xy)) {
					openTile(p);
				}
			}
		}

		else if (this->at(xy).isMine) {
			announceLoss();
			quit.show();
			restart.show();
			labelCover.set_fill_color(labelCover.color());
		}
	}

	if (win()) {
		annouceWin();
		quit.show();
		restart.show();
		labelCover.set_fill_color(labelCover.color());
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	if (this->at(xy).state == Cell::flagged || this->at(xy).state == Cell::closed) {
		this->at(xy).flag();

		++flaggedTiles;
		minesLeft.put(to_string(mines - flaggedTiles));
	}
}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}

bool MinesweeperWindow::win() {
	return (openedTiles >= width * height - mines);
}

void MinesweeperWindow::announceLoss() {
	minesLeft.put("YOU LOST!");

	for (Tile* t : tiles) {
		if (t->isMine) {
			t->set_label("X");
			t->set_label_color(Color::dark_red);
		}
	} 
}

void MinesweeperWindow::annouceWin() {
	minesLeft.put("YOU WIN!");

	for (Tile* t : tiles) {
		if (t->isMine) {
			t->set_label(cellToSymbol.at(Cell::flagged));
			t->set_label_color(Color::blue);
		}
	}
}

void MinesweeperWindow::cb_quit(Address, Address pw) {
	reference_to<MinesweeperWindow>(pw).hide();
}

void MinesweeperWindow::restartGame() {
	for (Tile* t : tiles) {
		t->reset();
	}

	for (int i{ 0 }; i < mines; ++i) {
		int random{ rand() % (width * height) };

		while (tiles[random].isMine) {
			random -= 1;
			if (random == 0) { random = width * height - 1; }
		}

		tiles[random].isMine = true;
	}

	flaggedTiles = 0;
	openedTiles = 0;

	quit.hide();
	restart.hide();
	minesLeft.put(to_string(mines));
	labelCover.set_fill_color(Color::invisible);
}

void MinesweeperWindow::cb_restart(Address, Address pw) {
	reference_to<MinesweeperWindow>(pw).restartGame();
}