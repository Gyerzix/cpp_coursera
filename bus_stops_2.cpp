#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	int m = 1; // номер автобуса
	map<int, vector<string>> bus_stops;
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int c = 0; // 1 - если есть такой маршрут, иначе - 0
		int j; // номер существующего автобуса
		int count_stops; cin >> count_stops;
		vector<string> v(count_stops);
		for (string& s : v) { // Вместо push_back лучше так делать, так как в условии == порядок учитывается. (но это неточно)
			cin >> s;
		}

		for (const auto& item : bus_stops) {
			if (item.second == v) {
				c = 1;
				j = item.first;
			}
		}
		if (c == 1) {
			cout << "Already exists for " << j << endl;
		}
		else if (c == 0) {
			bus_stops[m] = v;
			cout << "New bus " << m << endl;
			m += 1;
		}
	}
	return 0;
}
