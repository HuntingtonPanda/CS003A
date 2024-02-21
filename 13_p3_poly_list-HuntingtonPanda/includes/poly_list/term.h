#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <iomanip>
#include "assert.h"

using namespace std;

bool double_equals(double left, double right){return (int)(left*100) == (int)(right*100);}

struct Term{
    double _coef;
    int _exp;

    Term();
    Term(double coef, int order);

    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //used in Poly division operator
    friend Term operator + (const Term& lhs, const Term& rhs);
    friend Term operator - (const Term& lhs, const Term& rhs);
    friend Term operator * (const Term& lhs, const Term& rhs);
    friend Term operator / (const Term& lhs, const Term& rhs);

    friend ostream& operator <<(ostream& outs, const Term& t);
    friend istream& operator >>(istream& ins, Term& t);
    Term operator -() const; //unary operator
};

#endif