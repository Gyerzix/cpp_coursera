#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int Q; cin >> Q;
    map<string, set<string>> word_synonyms;
    string command;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            word_synonyms[word1].insert(word2);
            word_synonyms[word2].insert(word1);
        }

        else if (command == "COUNT") {
            string s; cin >> s;
            cout << word_synonyms[s].size() << endl;
        }

        else if (command == "CHECK") {
            int c = 0;
            string word1, word2;
            cin >> word1 >> word2;
            if (word_synonyms[word1].count(word2)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}