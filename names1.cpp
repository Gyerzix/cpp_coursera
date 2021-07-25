#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
private:
    map<int, string> year_f;
    map<int, string> year_l;
    vector<int> VectorMax(int year, map<int, string> yeaar) {
        vector<int> result;
        for (const auto& item : yeaar) {
            if (item.first <= year) {
                result.push_back(item.first);
            }
        }
        return result;
    }
    int Max(const vector<int>& v) {
        int temp = 0;
        for (const auto& item : v) {
            if (item > temp) {
                temp = item;
            }
        }
        return temp;
    }

public:
    void ChangeFirstName(int year, const string& first_name) {
        year_f[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        year_l[year] = last_name;
    }
    string GetFullName(int year) {
        vector<int> years_f = VectorMax(year, year_f);
        vector<int> years_l = VectorMax(year, year_l);
        int max_f = Max(years_f);
        int max_l = Max(years_l);
        string first_name = year_f[max_f];
        string last_name = year_l[max_l];
        if (max_f == 0 && max_l == 0) {
            return "Incognito";
        }
        else if (max_f == 0 && max_l > 0) {
            return last_name + " " + "with unknown first name";
        } 
        else if (max_f > 0 && max_l == 0) {
            return first_name + " " + "with unknown last name";
        }
        return first_name + " " + last_name;
    }

};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
	return 0;
}