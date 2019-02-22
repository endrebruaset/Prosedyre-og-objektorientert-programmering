#include "fileOperations.h"

vector<int> countCharacters(string filename) {
	char character;
	vector<int> characterCount('z' - 'a' + 1); // 'z' - 'a' + 1 = 26

	ifstream file{ filename };
	if (!file) { error("Could not find file", filename); }

	while (file >> character) {
		if ('a' <= tolower(character) && tolower(character) <= 'z') { ++characterCount[tolower(character) - 'a']; }
	}

	for (unsigned int i{ 0 }; i < characterCount.size(); ++i) {
		cout << static_cast<char>('a' + i) << ": " << characterCount[i] << endl;
	}

	return characterCount;
}