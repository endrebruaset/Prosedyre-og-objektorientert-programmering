#include "std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"
#include "Blackjack.h"

// Oppgave 1e)
// 1) Det er en fordel å bruke symboler fremfor strenger og heltall fordi typesikkerheten blir mye bedre.
// 2) Med typene "string" og "int" må vi også være mye mer forsiktig med riktig navngivning og eventuell casting.

// Oppgave 3i)
// Vi ønsker å bruke en klasse fordi et kort har et sett spesifikke verdier som er gyldige, noe struct ikke tar hensyn til.
// Klassens invariant er at kortet har en av de fire fargene i en kortstokk, og en verdi fra 1 til ess.

int main(){

	srand(static_cast<unsigned int>(time(nullptr)));

	int choice{ -1 };
	while (choice != 0) {
		cout << "0: quit" << endl
			<< "1: toString() and toStringShort() for cardStruct" << endl 
			<< "2: toString() and toStringShort() for Card" << endl 
			<< "3: print(), printShort(), shuffle() and drawCard() for CardDeck" << endl 
			<< "4: playBlackjack()" << endl << endl;
		cin >> choice;

		switch (choice) {
		case 0: 
			continue;
		case 1:
		{
			CardStruct card;
			card.s = Suit::clubs;
			card.r = Rank::nine;
			cout << toString(card) << endl;
			cout << toStringShort(card) << endl << endl;

			break;
		}
		case 2:
		{
			Card randomCard{ Suit::diamonds, Rank::jack };
			cout << randomCard.toString() << endl;
			cout << randomCard.toStringShort() << endl << endl;
			
			Card invalidCard;
			cout << invalidCard.toString() << endl << endl;

			break;
		}
		case 3:
		{
			CardDeck completeDeck{ CardDeck() };
			completeDeck.print();
			cout << endl;

			completeDeck.printShort();
			cout << endl << endl;

			completeDeck.shuffle();
			completeDeck.print();
			cout << endl;

			Card firstCard{ completeDeck.drawCard() };
			cout << "First card: " << firstCard.toString() << endl << endl;
			Card secondsCard{ completeDeck.drawCard() };
			cout << "Second card: " << secondsCard.toString() << endl << endl;

			break;
		}
		case 4:
		{
			playBlackjack();
			break;
		}
		default:
		{
			cout << "wrong input" << endl << endl;
			break;
		}
		}
	}
	
	return 0;
}