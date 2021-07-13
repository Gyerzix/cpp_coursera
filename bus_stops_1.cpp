#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
	int Q; cin >> Q;
	string command; //Команда
	string bus; //Название автобуса
	string stopi; //Название остановки
	int stop_count; //Количество остановок автобуса
	map<string, vector<string>> bus_stops; //[автобус; остановки]
	map<string, vector<string>> stop_buses; //[остановка; автобусы]
	for (int i = 0; i < Q; i++) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus; cin >> stop_count;
			vector<string> v(stop_count);
			for (string& s : v) {
				cin >> s;
				vector<string> v2;
				v2.push_back(bus);
				if (stop_buses.count(s)) {
					stop_buses[s].insert(end(stop_buses[s]), begin(v2), end(v2));
				}
				else {
					stop_buses[s] = v2;
				}
			}
			bus_stops[bus] = v;

		}

		else if (command == "BUSES_FOR_STOP") {
			cin >> stopi;
			if (stop_buses[stopi].size() == 0) {
				cout << "No stop" << endl;
			}
			else {
				for (const auto& item : stop_buses) {
					if (item.first == stopi) {
						for (int j = 0; j < item.second.size(); j++) {
							cout << item.second[j] << " ";
						}
					}
				}
			}
		}

		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			if (bus_stops.count(bus) > 0) {
				for (const auto& item1 : bus_stops) {
					if (item1.first == bus) {
						for (auto s : item1.second) {
							cout << "Stop " << s << ": ";
							for (const auto& item2 : stop_buses) {
								if (item2.first == s) {
									if (item2.second.size() == 1) {
										cout << "no interchange" << endl;
									}
									else {
										for (auto w : item2.second) {
											if (w != bus) {
												cout << w << " ";
											}
										}
										cout << endl;
									}
								}
							}
						}
					}
				}
			}
			else {
				cout << "No bus" << endl;
			}
		}

		else if (command == "ALL_BUSES") {
			if (bus_stops.size() == 0) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& item : bus_stops) {
					cout << "Bus " << item.first << ": ";
					for (int h = 0; h < item.second.size(); h++) {
						cout << item.second[h] << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}