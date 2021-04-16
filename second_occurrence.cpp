#include <iostream>
#include <string>
using namespace std;
int main() {
	string w;
	cin >> w;
	int count = 0;
	for (int i = 0; i < w.size(); ++i) {
		if (w[i] == 'f') {
			count+=1;
		}
        if (count >= 2) {
          cout << i;
          break;
        }
	}
	if (count == 1) {
		cout << -1;
	}
	else if (count == 0) {
		cout << -2;
	}
	return 0;
}