#pragma once

#include <memory>
#include <iostream>
#include <string>

// test code 
void testLinkedListTemplate();

template <class T>
class Node {
private:
	const T value;    // The data held by the LinkedList
	std::unique_ptr<Node> next; // unique_ptr to the next node
	Node* prev;                 // raw (non-owning) ptr to the previous node
public:
	Node() : value(), next(nullptr), prev(nullptr) {}

	// construct a node with T value, a unique_ptr to the next node, and a pointer to the previous node
	Node(const T& value, std::unique_ptr<Node> next, Node* prev)
		: value(value)
		, next(std::move(next))
		, prev(prev)
	{}

	// We can use the default destructor, since unique_ptr takes care of deleting memory
	~Node() = default;

	// return the value of the node
	T getValue() const { return value; }

	// return a raw (non-owning) pointer to the next node
	Node* getNext() const { return next.get(); }
	// return a raw (non-owning) pointer to the previous node
	Node* getPrev() const { return prev; }

	template <class T> friend class LinkedList;
};

// write the value of the node to the ostream
template<class T>
std::ostream & operator<<(std::ostream & os, const Node<T>& node)
{
	os << node.getValue();
	return os;
}

template <class T>
class LinkedList {
private:
	// ptr to the first node
	std::unique_ptr<Node<T>> head;
	// a raw pointer to the last node, the last node is always a dummy node
	// this is declared as a const ptr to a Node, so that tail never can
	// point anywhere else
	Node<T>* const tail;
public:
	//create the dummy node, and make tail point to it
	LinkedList()
		: head(std::make_unique<Node<T>>())
		, tail(head.get())
	{}
	~LinkedList() = default;

	//if next is a nullptr (i.e. head is the dummy node), the list is emtpy
	bool isEmpty() const { return !head->next; }


	//return a pointer to first element
	Node<T>* begin() const { return head.get(); }
	//return a pointer to beyond-end element
	Node<T>* end() const { return tail; }

	// The insert function takes a pointer to node (pos) and a string (value). It creates a new
	// node which contains value. The new node is inserted into the LinkedList BEFORE the
	// node pointed to by pos.
	Node<T>* insert(Node<T>* pos, const T& value)
	{
		if (pos == head.get()) {
			head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
			head->next->prev = head.get();

			return head.get();
		}
		else {
			pos->prev->next = std::make_unique<Node<T>>(value, std::move(pos->prev->next), pos->prev);
			pos->prev = pos->prev->next.get();

			return pos->prev;
		}
	}

	// The find function traverses the linked list and returns a pointer to the first node
	// that contains the value given.
	// If the value isn't in the list, find returns a pointer to the dummy node at the end
	// of the list.
	Node<T>* find(const T& value)
	{
		Node<T>* traverser = head.get();
		while (traverser != tail) {
			if (traverser->value == value) {
				return traverser;
			}

			traverser = traverser->next.get();
		}

		return tail;
	}

	// The remove function takes a pointer to a node, and removes the node from the list. The
	// function returns a pointer to the element after the removed node.
	Node<T>* remove(Node<T>* pos)
	{
		Node<T>* prevNode = pos->prev;

		pos->next->prev = prevNode;
		prevNode->next = move(pos->next);

		return prevNode->next.get();
	}

	// The remove function takes a string and removes the first node which contains the value.
	void remove(const T value)
	{
		if (find(value) != tail) {
			LinkedList::remove(find(value));
		}
	}
};

template <class T>
std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list)
{
	Node<T>* ptr = list.begin();
	while (ptr != list.end()) {
		os << ptr->getValue() << " ";
		ptr = ptr->getNext();
	}
	return os;
}

void testLinkedListTemplate() {
	{ 
	LinkedList<int> list{};
	list.insert(list.end(), 1);
	list.insert(list.end(), 2);
	list.insert(list.end(), 3);
	list.insert(list.end(), 4);

	std::cout << "Opprinnelig liste: \n" << list << "\n\n";
	std::cout << "Legg til 11 foran 3: \n";

	list.insert(list.find(3), 11);

	std::cout << list << "\n\n";
	std::cout << "Fjern 2: \n";

	list.remove(2);

	std::cout << list << "\n\n\n";
	}

	{
	LinkedList<char> list{};
	list.insert(list.end(), 'a');
	list.insert(list.end(), 'b');
	list.insert(list.end(), 'c');
	list.insert(list.end(), 'd');

	std::cout << "Opprinnelig liste: \n" << list << "\n\n";
	std::cout << "Legg til 't' foran 'c': \n";

	list.insert(list.find('c'), 't');

	std::cout << list << "\n\n";
	std::cout << "Fjern 'b': \n";

	list.remove('b');

	std::cout << list;
	}
}


/*

For å bruke template i LinkedList må vi vite at typen har overlastet alle operatorer som brukes,
f. eks. <<-operatoren og ==-operatoren, er overlastet. Typen må også ha default-konstruktør og kopikonstruktør.

*/