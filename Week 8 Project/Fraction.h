#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify(); // Simplify the fraction when initialized
    }

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

    Fraction operator+(const Fraction& other) const {
        int commonDenominator = denominator * other.denominator;
        int num = numerator * other.denominator + other.numerator * denominator;
        return Fraction(num, commonDenominator);
    }

    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        // Cross-multiply to compare without converting to floats
        return (numerator * other.denominator) > (other.numerator * denominator);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }
};
