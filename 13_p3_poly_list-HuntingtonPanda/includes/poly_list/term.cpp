#include "term.h"
#include "assert.h"

Term:: Term(): _coef(0), _exp(0){}

Term:: Term(double coef, int order): _coef(coef), _exp(order){}

Term& Term::operator +=(const Term& rhs){
    assert(rhs._exp == _exp);

    _coef += rhs._coef;

    return *this;
}
Term& Term::operator -=(const Term& rhs){
    *this += -(rhs);

    return *this;
}

Term& Term::operator *=(const Term& rhs){
    _coef *= rhs._coef;
    _exp += rhs._exp;

    return *this;

}

Term& Term::operator /=(const Term& rhs){
    assert(rhs._exp != 0);

    _coef /= rhs._coef;
    _exp -= rhs._exp;

    return *this;
}

bool operator ==(const Term& lhs, const Term& rhs){
    // return double_equals(lhs._coef, rhs._coef) && (lhs._exp == rhs._exp);
    return (lhs._exp == rhs._exp);
}

bool operator !=(const Term& lhs, const Term& rhs){
    return !(lhs == rhs);
}

bool operator >(const Term& lhs, const Term& rhs){
    if (lhs._exp > rhs._exp)
        return true;

    // if (lhs._exp == rhs._exp && lhs._coef > rhs._coef)
    //     return true;

    return false;
}

bool operator <(const Term& lhs, const Term& rhs){
    return rhs > lhs;
}

//used in Poly division operator
Term operator + (const Term& lhs, const Term& rhs){
    assert(lhs._exp == rhs._exp);

    Term temp(lhs._coef + rhs._coef, lhs._exp);

    return temp;
}

Term operator - (const Term& lhs, const Term& rhs){
    return lhs + (-rhs);
}

Term operator * (const Term& lhs, const Term& rhs){
    Term temp(lhs._coef * rhs._coef, lhs._exp + rhs._exp);

    return temp;
}

Term operator / (const Term& lhs, const Term& rhs){
    Term temp(0, lhs._exp - rhs._exp);
    temp._coef = lhs._coef / rhs._coef;

    return temp;
}

ostream& operator <<(ostream& outs, const Term& t){
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

istream& operator >>(istream& ins, Term& t){
    char c;

    ins >> t._coef >> c >> t._exp;

    return ins;
}

Term Term::operator -() const{
    Term temp(_coef*-1, _exp);
    
    return temp;

} //unary operator