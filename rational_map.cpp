#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() { // Реализуйте конструктор по умолчанию
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) { // Реализуйте конструктор
        if (numerator > 0 && denominator < 0) {
            int k = gcd(abs(numerator), abs(denominator));
            if (gcd(abs(numerator), abs(denominator))) {
                num = -numerator / k;
                den = -denominator / k;
            }
            else {
                num = -numerator;
                den = -denominator;
            }

        }
        else if (numerator < 0 && denominator < 0) {
            int k = gcd(abs(numerator), abs(denominator));
            if (gcd(abs(numerator), abs(denominator))) {
                num = -numerator / k;
                den = -denominator / k;
            }
            else {
                num = -numerator;
                den = -denominator;
            }
        }
        else if (numerator == 0) {
            num = 0;
            den = 1;
        }
        else {
            int k = gcd(abs(numerator), abs(denominator));
            if (gcd(abs(numerator), abs(denominator))) {
                num = numerator / k;
                den = denominator / k;
            }
            else {
                num = numerator;
                den = denominator;
            }
        }
    }

    int Numerator() const { // Реализуйте этот метод
        return num;
    }

    int Denominator() const { // Реализуйте этот метод
        return den;
    }
    int size() {

    }
private:
    int num;
    int den;
};


// Вставьте сюда реализацию operator == для класса Rational из второй части
bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а

bool operator < (const Rational& lhs, const Rational& rhs) {
    int denominator = lhs.Denominator() * rhs.Denominator();
    int lhs_num = lhs.Numerator() * rhs.Denominator();
    int rhs_num = rhs.Numerator() * lhs.Denominator();
    if (lhs_num < rhs_num) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
