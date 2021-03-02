#include "fraction.h"
#include <iostream>

static int32_t gcd(int32_t a, int32_t b) {
    int32_t r;

    a = (a >= 0) ? a : -a;
    b = (b >= 0) ? b : -b;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

Fraction::Fraction(int32_t n, int32_t d) {
    int32_t g;
    
    if (d < 0) {
        n = -n;
        d = -d;
    }

    g = gcd(n,d);

    num = n/g;
    den = d/g;
}

Fraction::~Fraction(void) {}

Fraction Fraction::operator+(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.den + den * rhs.num;
    t = den * rhs.den;

    return Fraction(s,t);
}

Fraction Fraction::operator-(Fraction rhs) {
    int32_t s, t;

    s = num * rhs.den - den * rhs.num;
    t = den * rhs.den;

    return Fraction(s,t);
}

Fraction Fraction::operator*(Fraction rhs) {
    return Fraction(num * rhs.num, den * rhs.den);
}

Fraction Fraction::operator/(Fraction rhs) {
    return Fraction(num * rhs.den, den * rhs.num);
}

bool Fraction::operator==(Fraction rhs) {
    return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {
    return num != rhs.num || den != rhs.den;
}

bool Fraction::operator<(Fraction rhs) {
    return num * rhs.den < den * rhs.num;
}

bool Fraction::operator<=(Fraction rhs) {
    return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {
    return num * rhs.den > den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {
    return num * rhs.den >= den * rhs.num;
}

std::istream &operator>>(std::istream &is, Fraction &f) {
    int32_t n, d;
    char slash;

    is >> n >> slash >> d;

    f = Fraction(n,d);

    return is;
}

std::ostream &operator<<(std::ostream &os, Fraction f) {
    if (f.getNum() == 0) {
        os << 0;
    } else if (f.getDen() == 1) {
        os << f.getNum();
    } else {
        os << f.getNum() << " / " << f.getDen();
    }
    
    return os;
}