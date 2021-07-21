#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

void Print (const vector<string>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
}

bool NonRegistr(string s1, string s2) {
	string temp1 = s1;
	string temp2 = s2;
	transform(temp1.begin(), temp1.end(), temp1.begin(), [](unsigned char c) { return std::tolower(c); });
	transform(temp2.begin(), temp2.end(), temp2.begin(), [](unsigned char c) { return std::tolower(c); });
	if (temp1 > temp2) {
		return false;
	}
	return true;
}


int main() {
	int N; cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), NonRegistr);
	Print(v);

	return 0;
}