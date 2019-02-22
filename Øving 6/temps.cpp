#include "temps.h"

Temps::Temps() : max{0}, min{0} {}

istream& operator>>(istream& is, Temps& t) {
	Temps tt; // (0,0)
	if (is >> t.max >> t.min) { return is; }
	else { t = tt; return is; }
}

vector<Temps> readTemperatures(string filename) {
	ifstream file{ filename };
	if (!file) { error("Could not find file: ", filename); }

	Temps temp;
	vector<Temps> temperatures;

	while (file >> temp) {
		temperatures.push_back(temp);
	}

	return temperatures;
}

void plotTemperatures() {
	vector<Temps> temperatures{ readTemperatures("temperatures.txt") };

	constexpr int xmax{ 1000 };
	constexpr int ymax{ 600 };
	constexpr int xoffset{ 100 };
	constexpr int yoffset{ 60 };
	constexpr int xspace{ 100 };
	constexpr int yspace{ 60 };

	constexpr int xlength{ xmax - xoffset - xspace };
	constexpr int ylength{ ymax - yoffset - yspace };

	constexpr int numberOfDays{ 366 };
	constexpr int lowestTemp{ 30 };
	constexpr int higestTemp{ -30 };

	constexpr double xscale{ static_cast<double>(xlength) / numberOfDays };
	constexpr double yscale{ static_cast<double>(ylength) / (higestTemp - lowestTemp) };

	Scale xs{ xoffset, 0, xscale };
	Scale ys{ ymax / 2, 0, yscale };

	Simple_window win{ Point{100,100}, xmax, ymax, "Daily temperatures from February 3rd 2018 to February 3rd 2019" };
	Axis x{ Axis::x, Point{xoffset, ymax / 2}, xlength, 12, // antall måneder
		"Feb           Mar           Apr           May           Jun           Jul          "
		"Aug           Sep           Oct           Nov           Dec           Jan" };
	Axis y{ Axis::y, Point{xoffset, ymax - yoffset}, ylength, 6, 
		"degrees [°C]" };
	x.label.move(-145, 0); // måtte prøve meg frem her

	Open_polyline maxTemps;
	Open_polyline minTemps;

	for (unsigned int i{ 0 }; i < temperatures.size(); ++i) {
		const int x{ xs(i) };
		maxTemps.add(Point{ x, ys(temperatures.at(i).max) });
		minTemps.add(Point{ x, ys(temperatures.at(i).min) });
	}

	Text y_label_20{ Point{75, yoffset + ylength / 6}, " 20" }; // finnes en bedre måte for dette?
	Text y_label_10{ Point{75, yoffset + ylength * 2 / 6}, " 10" };
	Text y_label_0{ Point{75, yoffset + ylength * 3 / 6}, "  0" };
	Text y_label_neg10{ Point{75, yoffset + ylength * 4 / 6}, "-10" };
	Text y_label_neg20{ Point{75, yoffset + ylength * 5 / 6}, "-20" };
	y_label_20.set_color(Color::black);
	y_label_10.set_color(Color::black); 
	y_label_0.set_color(Color::black); 
	y_label_neg10.set_color(Color::black); 
	y_label_neg20.set_color(Color::black); 
	win.attach(y_label_20); 
	win.attach(y_label_10); 
	win.attach(y_label_0); 
	win.attach(y_label_neg10); 
	win.attach(y_label_neg20);

	x.set_color(Color::black);
	y.set_color(Color::black);
	maxTemps.set_color(Color::red);
	minTemps.set_color(Color::blue);

	win.attach(maxTemps);
	win.attach(minTemps);

	win.attach(x);
	win.attach(y);	

	gui_main();
}