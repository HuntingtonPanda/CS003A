#include <iostream>
#include "term.h"
#include "assert.h"
#include <math.h>

using namespace std;

Term::Term(double coef, int exp) : _coef(coef), _exp(exp)
{
}

bool operator==(const Term &lhs, const Term &rhs)
{
    return (lhs._exp == rhs._exp);

    //return ((int)(lhs._coef*1000) == (int)(rhs._coef*1000)) && (lhs._exp == rhs._exp);
}
bool operator!=(const Term &lhs, const Term &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const Term &lhs, const Term &rhs)
{
    if (lhs._exp > rhs._exp)
        return true;

    if (lhs._exp == rhs._exp && lhs._coef > rhs._coef)
        return true;

    return false;
}
bool operator<(const Term &lhs, const Term &rhs)
{
    return rhs > lhs;
}

Term operator+(const Term &lhs, const Term &rhs)
{
    assert(lhs._exp == rhs._exp);

    Term temp(lhs._coef + rhs._coef, lhs._exp);

    return temp;
}

Term operator-(const Term &t)
{
    Term temp(t._coef * -1, t._exp);

    return temp;
}

Term operator-(const Term &lhs, const Term &rhs)
{
    return lhs + (-rhs);
}

Term operator*(const Term &lhs, const Term &rhs)
{

    Term temp(lhs._coef * rhs._coef, lhs._exp + rhs._exp);

    return temp;
}

Term operator/(const Term &lhs, const Term &rhs)
{

    Term temp(0, lhs._exp - rhs._exp);
    temp._coef = lhs._coef / rhs._coef;

    return temp;
}

ostream &operator<<(ostream &outs, const Term &t)
{
    if (t._coef == 0)
        return outs;

    if (t._coef > 0)
        outs << "+";

    outs << t._coef;

    if (t._exp == 1)
        outs << "X ";
    else if (t._exp != 0)
        outs << "X^" << t._exp << " ";

    outs << " ";
    return outs;
}
