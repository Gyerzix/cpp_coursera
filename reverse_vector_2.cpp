#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> result;
	const int n = v.size();
	for (int i = 0; i < n; i++) {
		result.push_back(v[n - i - 1]);
	}
	return result;
}

void print(const vector<int>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
}


int main() {
	vector<int> v = { 5, 4, 3, 2, 1 };
	vector<int> s = Reversed(v);
	print(s);
	return 0;
}