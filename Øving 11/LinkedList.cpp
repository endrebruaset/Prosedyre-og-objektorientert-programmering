#include "LinkedList.h"
#include <iostream>
#include <string>

// Medlemsvariabelen prev i Node er ikke en std::unique_ptr for at det skal kunne slettes elementer fra listen, 
// uten at hele listen blir slettet.

std::ostream & LinkedList::operator<<(std::ostream & os, const Node & node)
{
	os << node.value;
	return os;
}

std::ostream & LinkedList::operator<<(std::ostream & os, const LinkedList & list)
{
	Node* ptr = list.head.get();
	while (ptr != list.tail) {
		os << ptr->getValue() << " ";
		ptr = ptr->getNext();
	}
	return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(Node * pos, const std::string & value)
{
	if (pos == head.get()) {
		head = std::make_unique<Node>( value, std::move(head), nullptr );
		head->next->prev = head.get();

		return head.get();
	}
	else {
		pos->prev->next = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
		pos->prev = pos->prev->next.get();
		
		return pos->prev;
	}
}

LinkedList::Node * LinkedList::LinkedList::find(const std::string & value)
{
	Node* traverser = head.get();
	while (traverser != tail) {
		if (traverser->value == value) {
			return traverser;
		}

		traverser = traverser->next.get();
	}

	return tail;
}

LinkedList::Node * LinkedList::LinkedList::remove(Node * pos)
{
	Node* prevNode = pos->prev;

	pos->next->prev = prevNode;
	prevNode->next = move(pos->next);

	return prevNode->next.get();
}

void LinkedList::LinkedList::remove(const std::string & value) 
{
	if (find(value) != tail) {
		LinkedList::remove(find(value));
	}
}

void testLinkedList() {
	LinkedList::LinkedList list{};
	list.insert(list.end(), "Endre");
	list.insert(list.end(), "er");
	list.insert(list.end(), "veldig");
	list.insert(list.end(), "flink");

	std::cout << list << '\n';

	list.insert(list.find("veldig"), "ikke");

	std::cout << list << '\n';

	list.remove("veldig");

	std::cout << list;
}


/* Teorispørsmål

i)  Det er bedre å bruke lenkede lister hvis vi er opptatte av enkel innsetting, å lagre
	data av forskjellige størrelser, og spesielt er det enklere å forandre størrelsen til en lenket
	liste. I et array vil en innsetting av et element tidlig i arrayet gjøre forandringer på
	indekseringen på alle påfølgende elementer. Man kan også iterere gjennom en lenket liste samtidig
	som det gjøres forandringer (find, replace, print).

ii) Det å lage stack eller queue handler bare om hvilke pekere som peker hvor, og i hvilken
	rekkefølge iteratorer traverserer listen. Dermed holder det å gjøre forandringer på head, tail,
	og funksjonenes traverseringsrekkefølge.

*/