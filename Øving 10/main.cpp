#include "MinesweeperWindow.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Fl::background(200, 200, 200);
	constexpr int width = 15;
	constexpr int height = 15;
	constexpr int mines = 30;

	Point startPoint{ 200,100 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();

}
 