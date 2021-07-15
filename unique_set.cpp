#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;
	set<string> unique;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		unique.insert(s);
	}
	cout << unique.size() << endl;
	return 0;
}