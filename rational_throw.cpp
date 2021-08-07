#include <iostream>
#include <exception>
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
        else if (denominator == 0) {
            throw invalid_argument("");
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

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
