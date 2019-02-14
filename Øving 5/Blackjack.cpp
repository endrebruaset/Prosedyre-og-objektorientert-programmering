#include "Blackjack.h"

Blackjack::Blackjack() {
	deck = CardDeck();
	deck.shuffle();

	for (int i{ 0 }; i < 2; ++i) {					// gives both dealer and player two cards each
		playerHand.push_back(deck.drawCard());
		dealerHand.push_back(deck.drawCard());
	}

	keepHand = false;
}

int Blackjack::handValue(vector<Card> hand) {
	int value{ 0 };
	int aces{ 0 };
	
	for (Card card : hand) {
			switch (card.rank()) {
			case Rank::jack:
				value += 10; break;
			case Rank::queen:
				value += 10; break;
			case Rank::king:
				value += 10; break;
			case Rank::ace:
				++aces; break;
			default:
				value += static_cast<int>(card.rank()); break;
			}
		}

	for (int i{ 0 }; i < aces; ++i) {
			if (value + 11 > 21) { value += 1; } // Dersom et ess med verdi 11 ville overskride 21 poeng blir verdien 1.
			else { value += 11; }
		}

	return value;
}

void Blackjack::dealerDraw() {
	while (handValue(dealerHand) < 17) {		// 17 er den minste verdien dealerens hånd kan ha
		dealerHand.push_back(deck.drawCard());
	}
}

void Blackjack::playerDraw() {
	string s;
	bool validInput{ false };
	do { // Ta inn ja eller nei med hensyn til noe feil input
		cout << "Do you want to draw another card [y / n]? " << endl;
		cin >> s;
		cout << endl;

		if (cin.fail()) {
			cin.clear(); // set the state back to good
			cout << "not a character, try again" << endl;
		}

		else if (cin) {
			if (s.length() != 1) {
				cout << "not a character, try again" << endl;
			}
			else {
				if (tolower(s[0]) == 'y') { validInput = true; }
				else if (tolower(s[0]) == 'n') { keepHand = true; validInput = true; }
				else { cout << "invalid input, try again" << endl; }
			}
		}

	} while (!validInput);

	if (!keepHand) {
		playerHand.push_back(deck.drawCard());
	}
}

void Blackjack::printHand() {
	cout << "Your current hand:" << endl;
	for (Card card : playerHand) {
		cout << "   " << card.toString() << endl;
	}
	cout << endl;
}

void Blackjack::decideWinner() {
	int playerValue{ handValue(playerHand) };
	int dealerValue{ handValue(dealerHand) };

	cout << "Your hand: " << endl;
	for (Card card : playerHand) {
		cout << "   " << card.toString() << endl;
	}
	cout << "Your hand's value: " << playerValue << endl << endl;

	cout << "The dealers hand: " << endl;
	for (Card card : dealerHand) {
		cout << "   " << card.toString() << endl;
	}
	cout << "The dealer's value: " << dealerValue << endl << endl;

	if (playerValue > 21) {
		cout << "The dealer wins!" << endl << endl;
	}
	else if (playerValue > dealerValue) {
		cout << "You win!" << endl << endl;
	}
	else if (playerValue < dealerValue) {
		if (dealerValue > 21) { cout << "You win!" << endl << endl; }
		else if (dealerValue <= 21 ) { cout << "The dealer wins!" << endl << endl; }
	}
	else { // hendene har samme verdi
		if ((playerHand.size() == 2 && playerValue == 21) && !(dealerHand.size() == 2 && dealerValue == 21)) {
			// spilleren har ekte blackjack mens dealeren ikke har det
			cout << "You win!" << endl << endl;
		}
		else { cout << "The dealer wins!" << endl << endl; }
	}
}

void playBlackjack() {
	Blackjack blackjack{ Blackjack() };

	blackjack.dealerDraw(); // gives the dealer cards until value is greater than or equal to 17
	blackjack.printHand();

	while (!blackjack.playerKeepHand()) { // while the player wants to draw new cards
		blackjack.playerDraw();
		blackjack.printHand();
	}

	blackjack.decideWinner();
}