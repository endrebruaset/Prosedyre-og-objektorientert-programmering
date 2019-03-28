#include "iterators.h"
#include "Person.h"
#include "LinkedList.h"
#include "Template.h"
#include "LinkedListTemplate.h"

#include <locale>

int main() {

	setlocale(LC_ALL, "norwegian");

	int choice{ -1 };
	while (choice != 0) {
		cout << "0: quit" << endl
			<< "1: Vector: forward iterator, reverese iterator, and replace()" << endl
			<< "2: Set: forward iterator, reverese iterator, and replace()" << endl
			<< "3: InsertOrdered()" << endl
			<< "4: testLinkedList()" << endl 
			<< "5: maximum() and shuffle()" << endl << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			continue;
		case 1:
		{
			vector<string> v{ "Endre", "Lasse", "Eskil" };

			cout << "Forward iterator:" << endl;
			vectorForwardIterator(v);

			cout << endl << "Reverse iterator:" << endl;
			vectorReverseIterator(v);

			cout << endl << "Replace \"Eskil\" with \"Nora\"" << endl;
			vectorReplace(v, "Eskil", "Nora");
			vectorForwardIterator(v);
			cout << endl;

			break;
		}
		case 2:
		{
			set<string> s{ "Endre", "Lasse", "Eskil" };

			cout << "Forward iterator:" << endl;
			setForwardIterator(s);

			cout << endl << "Reverse iterator:" << endl;
			setReverseIterator(s);

			cout << endl << "Replace \"Eskil\" with \"Nora\"" << endl;
			setReplace(s, "Eskil", "Nora");
			setForwardIterator(s);
			cout << endl;

			break;
		}
		case 3:
		{
			list<Person> l;
			insertOrdered(l, Person("Endre", "Bruaset"));
			insertOrdered(l, Person("Lasse", "Wardenær"));
			insertOrdered(l, Person("Eskil", "Ould-Saada"));

			for (Person p : l) {
				cout << p << endl;
			}

			cout << endl;

			break;
		}
		case 4:
		{
			testLinkedList();
			cout << endl << endl;
			break;
		}
		case 5:
		{
			srand(time(NULL));

			cout << "Maximum of 3 and 4: " << maximum(3, 4) << endl;
			cout << "Maximum of 2.3 and 5.4: " << maximum(5.4, 2.3) << endl;
			cout << "Maximum of \"hei\" and \"hallo\": " << maximum("hei", "hallo") << endl << endl;

			vector<int> vecInt{ 1,2,3,4,5,6,7,8,9,10 };
			vector<char> vecChar{ 'a', 'b', 'c', 'd', 'e', 'f', 'g' };

			for (auto v : vecInt) {
				cout << v << " ";
			}
			cout << endl;

			for (auto v : vecChar) {
				cout << v << " ";
			}
			cout << endl;

			shuffle(vecInt); shuffle(vecChar);

			for (auto v : vecInt) {
				cout << v << " ";
			}
			cout << endl;

			for (auto v : vecChar) {
				cout << v << " ";
			}
			cout << endl << endl;

			break;
		}
		default:
			break;
		}
	}

	return 0;
}