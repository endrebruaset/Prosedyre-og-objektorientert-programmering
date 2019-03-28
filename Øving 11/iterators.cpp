#include "iterators.h"

void vectorForwardIterator(vector<string>& v) {
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
}

void vectorReverseIterator(vector<string>& v) {
	for (vector<string>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
		cout << *rit << endl;
	}
}

void vectorReplace(vector<string>& v, string old, string replacement) {
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		if (*it == old) { 
			it = v.erase(it);
			it = v.insert(it, replacement);
		}
	}
}

void setForwardIterator(set<string>& s) {
	for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << endl;
	}
}

void setReverseIterator(set<string>& s) {
	for (set<string>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
		cout << *rit << endl;
	}
}

void setReplace(set<string>& s, string old, string replacement) {
	for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
		if (*it == old) {  
			it = s.erase(it);
			it = s.insert(it, replacement);
		}
	}
}

