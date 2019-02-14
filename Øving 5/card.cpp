#include "card.h"

string suitToString(Suit suit) {
	const map<Suit, string> suitStrings{
		{Suit::clubs, "Clubs"},
		{Suit::diamonds, "Diamonds"},
		{Suit::hearts, "Hearts"},
		{Suit::spades, "Spades"} };

	return suitStrings.at(suit);
}
string rankToString(Rank rank) {
	const map<Rank, string> rankStrings{
		{Rank::two, "Two"},
		{Rank::three, "Three"},
		{Rank::four, "Four"},
		{Rank::five, "Five"},
		{Rank::six, "Six"},
		{Rank::seven, "Seven"},
		{Rank::eight, "Eight"},
		{Rank::nine, "Nine"},
		{Rank::ten, "Ten"},
		{Rank::jack, "Jack"},
		{Rank::queen, "Queen"},
		{Rank::king, "King"},
		{Rank::ace, "Ace"} };

	return rankStrings.at(rank);
}

// struct cardStruct

string toString(CardStruct card) {
	return rankToString(card.r) + " of " + suitToString(card.s);
}
string toStringShort(CardStruct card) {
	string str{ suitToString(card.s)[0] };			// First letter in Suit
	str += to_string(static_cast<int>(card.r));		// Rank as integer

	return str;
}

// class Card

Card::Card() { valid = false; }

Card::Card(Suit suit, Rank rank) : s{ suit }, r{ rank } { valid = true; }

string Card::toString() {
	if (Card::valid) 
		{ return rankToString(Card::r) + " of " + suitToString(Card::s); }
	else 
		{ return "Invalid card."; }
}

string Card::toStringShort() {
	if (Card::valid) 
	{
		string str{ suitToString(Card::s)[0] };
		str += to_string(static_cast<int>(Card::r));
		return str;
	}
	else 
		{ return "Invalid card."; }
}