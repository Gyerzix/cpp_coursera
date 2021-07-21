#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

void Print(const vector<int>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for (auto& item : v) {
		cin >> item;
	}
	sort(v.begin(), v.end(), [](int num1, int num2) {return abs(num1) < abs(num2); });
	Print(v);
	return 0;
}