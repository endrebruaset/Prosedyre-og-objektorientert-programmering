#include "cardDeck.h"

CardDeck::CardDeck() {
	constexpr int numberOfSuits{ 4 };
	constexpr int numberOfRanks{ 13 };

	for (int i{ 0 }; i < numberOfSuits; ++i) {
		for (int j{ 0 }; j < numberOfRanks; ++j) {
			cards.push_back(Card(Suit(i), Rank(j + 2))); // Rank enum class starts at two
		}
	}

	currentCardIndex = 0;
}

void CardDeck::swap(int firstIndex, int secondIndex) {
	Card temp{ cards[firstIndex] };
	cards[firstIndex] = cards[secondIndex];
	cards[secondIndex] = temp;
}

void CardDeck::print() {
	for (Card card : cards) {
		cout << card.toString() << endl;
	}
}

void CardDeck::printShort() {
	for (Card card : cards) {
		cout << card.toStringShort() << " ";
	}
}

void CardDeck::shuffle() {
	constexpr int amountOfSwaps{ 1000 };
	for (int i{ 0 }; i < amountOfSwaps; ++i) {
		int rand1{ rand() % 52 };	// random number between 0 and 51
		int rand2{ rand() % 52 }; 


		if (rand1 == rand2) {
			if (rand2 == 0) { ++rand2; }
			else { --rand2; }
		}

		swap(rand1, rand2);
	}
}

const Card& CardDeck::drawCard() {
	int drawingIndex{ currentCardIndex };
	++currentCardIndex;

	return cards[drawingIndex];
}