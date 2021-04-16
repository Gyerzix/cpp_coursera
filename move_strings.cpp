#include <iostream>
#include <string>
using namespace std;

void MoveStrings(vector<string>& s, vector<string>& d) {
	for (auto w : s) {
		d.push_back(w);
	}
	s.clear();
}