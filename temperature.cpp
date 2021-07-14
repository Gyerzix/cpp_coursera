#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k; cin >> k;
	int sum = 0;
	vector<int> v(k);
	for (int& s : v) {
		cin >> s;
	}
	int count = 0;
	for (const auto& item : v) {
		sum += item;
	}
	int mid = sum / k;
	for (const auto& item : v) {
		if (item > mid) {
			count++;
		}
	}
	cout << count << endl;
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > mid) {
			cout << i << " ";
		}
	}
	return 0;
}