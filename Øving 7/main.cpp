#include "Graph.h"
#include "Simple_window.h" 
#include "Emoji.h"

constexpr int xmax{ 800 };
constexpr int ymax{ 600 };
constexpr int emojiRadius{ 80 };

int main() {
	using namespace Graph_lib;
	
	const Point tl{ 100, 100 };
	Simple_window win{ tl, xmax, ymax, "Emojis" }; 

	Point topLeft{ 200, 200 };
	Point topMiddle{ 400, 200 };
	Point topRight{ 600, 200 };
	Point bottomLeft{ 200, 400 };
	Point bottomMiddle{ 400,400 };
	Point bottomRight{ 600,400 };

	Vector_ref<Emoji> emojis;
	emojis.push_back(new SmilingFace{ topLeft, emojiRadius });
	emojis.push_back(new SadFace{ bottomLeft, emojiRadius });
	emojis.push_back(new WinkingFace{ topMiddle, emojiRadius });
	emojis.push_back(new ConcernedFace{ bottomMiddle, emojiRadius });
	emojis.push_back(new RollingEyesFace{ topRight, emojiRadius });

	for (auto const& emoji : emojis) {
		emoji->attach_to(win);
	}

	win.wait_for_button();
}

