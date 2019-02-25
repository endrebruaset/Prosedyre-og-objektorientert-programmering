#pragma once
#include "Graph.h"
#include "Simple_window.h" 

class Emoji {
public:
	virtual void attach_to(Graph_lib::Window&) = 0;

	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	Emoji() {};
	virtual ~Emoji() {};
};

class Face : public Emoji {
public:
	virtual void attach_to(Graph_lib::Window&) override;

	Face(const Face&) = delete;
	Face& operator=(const Face&) = delete;

	Face(Point& center, int radius);
	virtual ~Face() {};

private:
	Circle face;
};

class EmptyFace : public Face {
public:
	void attach_to(Graph_lib::Window&) override;

	EmptyFace(Point& center, int radius);

private:
	Circle rightEye;
	Circle leftEye;
};

class SmilingFace : public EmptyFace {
public:
	void attach_to(Graph_lib::Window&) override;

	SmilingFace(Point& center, int radius);
private:
	Arc mouth;
};

class SadFace : public EmptyFace {
public:
	void attach_to(Graph_lib::Window&) override;

	SadFace(Point& center, int radius);
private:
	Arc mouth;
};

class WinkingFace : public Face {
public:
	void attach_to(Graph_lib::Window&) override;

	WinkingFace(Point& center, int radius);

private:
	Circle openEye;
	Circle openEyePupil;
	Open_polyline winkingEye;
	Ellipse mouth;
	Ellipse tounge;
};

class ConcernedFace : public EmptyFace {
public:
	void attach_to(Graph_lib::Window&) override;

	ConcernedFace(Point& center, int radius);
private:
	Arc rightEyebrow;
	Arc leftEyebrow;
	Line mouth;
};

class RollingEyesFace : public Face {
public:
	void attach_to(Graph_lib::Window&) override;

	RollingEyesFace(Point& center, int radius);
private:
	Circle rightEye;
	Circle leftEye;
	Circle rightPupil;
	Circle leftPupil;
	Ellipse mouth;
};