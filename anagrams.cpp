#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s) {
	map<char, int> result;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length(); j++) {
			if (s[i] == s[j]) {
				count++;
			}
		}
		result[s[i]] = count;
		count = 0;
	}
	return result;
}

void PrintMap(const map<char, int>& w) {
	cout << "Size = " << w.size() << endl;
	for (auto item : w) {
		cout << item.first << ": " << item.second << endl;
	}
}

int main() {
	int N; cin >> N;
	for (int k = 0; k < N; k++) {
		string s; cin >> s;
		string w; cin >> w;
		if (BuildCharCounters(s) == BuildCharCounters(w)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}