// defines int32_t and related aliases
#include <cstdint>
#include <iostream>

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction {
public:
    Fraction(int32_t n=0, int32_t d=1);
    ~Fraction(void);

    int32_t getNum() { return num;} // getter for numerator
    int32_t getDen() { return den;} // getter for denominator

    Fraction operator+(Fraction rhs);
    Fraction operator-(Fraction rhs);
    Fraction operator*(Fraction rhs);
    Fraction operator/(Fraction rhs);

    bool operator==(Fraction rhs);
    bool operator!=(Fraction rhs);
    bool operator<(Fraction rhs);
    bool operator<=(Fraction rhs);
    bool operator>(Fraction rhs);
    bool operator>=(Fraction rhs);
private:
    int32_t num, den;
};

std::istream &operator>>(std::istream &, Fraction &);
std::ostream &operator<<(std::ostream &, Fraction);

#endif