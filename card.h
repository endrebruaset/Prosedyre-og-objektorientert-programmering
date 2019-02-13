#pragma once
#include "std_lib_facilities.h"

enum class Suit {
	clubs,
	diamonds,
	hearts,
	spades
};

enum class Rank {
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};

struct CardStruct
{
	Suit s;
	Rank r;
};

class Card {
public:
	Card();
	Card(Suit suit, Rank rank);
	Suit suit() { return s; };
	Rank rank() { return r; };
	bool isValid() { return valid; };
	string toString();
	string toStringShort();
private:
	Suit s;
	Rank r;
	bool valid;
};


string suitToString(Suit suit);

string rankToString(Rank rank);

string toString(CardStruct card);

string toStringShort(CardStruct card);