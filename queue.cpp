#include <string>
#include <iostream>
#include <vector>

using namespace std;

void Worry(int& i, vector<bool>& x) {
    x[i] = true;
}

void Quiet(int& i, vector<bool>& x) {
    x[i] = false;
}
void Come(int n, vector<bool>& x) { 
    int q = x.size(); 
    x.resize(q + (n)); 
}
void Worry_count(const vector<bool>& x) {
    int counts = 0;
    for (auto i : x) {
        if (i==1) 
            counts++;
        }
    }
    cout << counts << endl;

int main() {
    int Q;
    cin >> Q;
    vector<bool> stack; 
    for (int i = 0; Q > i; i++) {
        string s;
        int col;
        cin >> s; 
        if (s == "WORRY_COUNT") { 
            Worry_count(stack); 
        }
        else {
            cin >> col; 
            if (s == "WORRY") { 
                Worry(col, stack);
            }
            else if (s == "QUIET") { 
                Quiet(col, stack); 
            }
            else if (s == "COME") { 
                Come(col, stack); 
            }
        }
    }
    return 0;
}