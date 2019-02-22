#include "courseCatalog.h"

void courseCatalog::addCourse(string code, string name) {
	courses.insert(pair<string, string>(code, name));
	// courses[code] = name;

	// operator[] erstatter objektet med nøkkel "code", mens .insert()
	// beholder det originale paret, da nøkkelen allerede er brukt i et par
}

void courseCatalog::removeCourse(string code) {
	courses.erase(code);
}

string courseCatalog::getCourse(string code) {
	return courses.at(code);
}

ostream& operator<<(ostream& out, const courseCatalog& courses) {
	for (pair<string, string> pair : courses.courses) {
		out << pair.first << "|" << pair.second << endl;
	}

	return out;
}

void testCourseCatalog() {
	try {
		courseCatalog courses;
		courses.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
		courses.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
		courses.addCourse("TMA4100", "Matematikk 1");

		courses.addCourse("TDT4102", "C++"); 

		cout << courses;

		courses.saveToFile("courseCatalog.txt");

		courseCatalog courses2;
		courses2.readFromFile("courseCatalog.txt");
		cout << courses2;
	}
	catch (exception& e) { cerr << "Exception: " << e.what() << endl; }
}

void courseCatalog::saveToFile(string filename) {
	ofstream file{ filename };
	if (!file) { error("Could not open file: ", filename); }

	for (pair<string, string> pair : courses) {
		file << pair.first << '|' << pair.second << '\n';
	}
}

void courseCatalog::readFromFile(string filename) {
	ifstream file{ filename };
	if (!file) { error("Could not find file: ", filename); }

	string line;
	string name;
	string code;

	while (getline(file, line)) {
		stringstream ss{ line };
		getline(ss, code, '|');
		getline(ss, name);
		addCourse(code, name);
	}
}