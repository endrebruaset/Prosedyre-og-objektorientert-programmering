#pragma once
#include "std_lib_facilities.h"

class courseCatalog {
private:
	map<string, string> courses;
public:
	void addCourse(string code, string name);
	void removeCourse(string code);
	string getCourse(string code);
	void saveToFile(string filename);
	void readFromFile(string filename);
	friend ostream& operator<<(ostream& out, const courseCatalog& courses);
};

void testCourseCatalog();