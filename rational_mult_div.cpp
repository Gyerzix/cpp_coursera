#include <iostream>
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

// Реализуйте для класса Rational операторы * и /
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
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

    cout << "OK" << endl;
    return 0;
}
