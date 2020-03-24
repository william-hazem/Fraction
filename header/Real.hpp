#ifndef REAL_H
#define REAL_H

#include "float_to_real.h"  //ftor -> float to Real
#include <iostream>         //ostream & istream

class Real
{
    friend std::ostream &operator<<(std::ostream &, const Real &);
    friend std::istream &operator>>(std::istream &, Real &);

private:
    int numerador, denominador;
    void simplify();
    int mdc(int, int);

public:
    Real();
    Real(int , int = 1);
    Real(float);
    Real(double);
    ~Real();

    Real &operator+(const Real &) const;
    Real &operator/(const Real &) const;
    Real &operator*(const Real &) const;
    Real &operator-() const;
    Real &operator-(const Real &) const;

    int getNumerador() const;
    int getDenominador() const;
    double get() const;
    void setNumerator(int);
    void setDenominator(int);
};  

#endif