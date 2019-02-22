#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h" 

struct Temps {
	double max;
	double min;
	Temps();
};

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemperatures(string filename);

class Scale {
	int cbase;
	int vbase;
	double scale;
public:
	Scale(int b, int vb, double s) : cbase{ b }, vbase{ vb }, scale{ s } {};
	int operator()(int v) const { return cbase + (v - vbase)*scale; };
};

void plotTemperatures();