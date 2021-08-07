#include <iostream>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>
#include <set>

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

// Реализуйте для класса Rational операторы ==, + и -

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    }
    return false;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    }

    else {
        int denominator = lhs.Denominator() * rhs.Denominator();
        return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), denominator);
    }
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator()) {
        return Rational(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
    }

    else {
        int denominator = lhs.Denominator() * rhs.Denominator();
        return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), denominator);
    }
}

// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

// Реализуйте для класса Rational операторы << и >>
ostream& operator<<(ostream& stream, const Rational& v) {
    stream << setfill('0');
    stream << v.Numerator() << '/' << v.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& v) {
    int n, d;
    char op;
    if (stream) {
        stream >> n >> op >> d;
        if (op == '/' && stream) {
            v = Rational(n, d);
        }
    }
    return stream;
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
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
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
