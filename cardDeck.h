#pragma once
#include "std_lib_facilities.h"
#include "card.h"

class CardDeck {
public:
	CardDeck();
	void swap(int firstIndex, int secondIndex);
	void print();
	void printShort();
	void shuffle();
	const Card& drawCard();
private:
	vector<Card> cards;
	int currentCardIndex;
};