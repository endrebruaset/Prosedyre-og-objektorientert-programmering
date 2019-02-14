#pragma once
#include "cardDeck.h"

class Blackjack {
public:
	Blackjack();
	int handValue(vector<Card> hand);
	void dealerDraw();
	void playerDraw();
	void printHand();
	void decideWinner();
	vector<Card> dealer() { return dealerHand; };
	vector<Card> player() { return playerHand; };
	bool playerKeepHand() { return keepHand; };
private:
	vector<Card> dealerHand;
	vector<Card> playerHand;
	CardDeck deck;
	bool keepHand;
};

void playBlackjack();