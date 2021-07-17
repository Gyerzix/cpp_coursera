#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	int m = 1; // номер автобуса
	map<int, set<string>> bus_stops;
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int c = 0; // 1 - если есть такой маршрут, иначе - 0
		int j; // номер существующего автобуса
		set<string> stops;
		int count_stops; cin >> count_stops;
		for (int j = 0; j < count_stops; j++) {
			string stop; cin >> stop;
			stops.insert(stop);
		}

		for (const auto& item : bus_stops) {
			if (item.second == stops) {
				c = 1;
				j = item.first;
			}
		}
		if (c == 1) {
			cout << "Already exists for " << j << endl;
		}
		else if (c == 0) {
			bus_stops[m] = stops;
			cout << "New bus " << m << endl;
			m += 1;
		}
	}
	return 0;
}
