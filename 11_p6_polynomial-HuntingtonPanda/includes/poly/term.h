#ifndef TERM_H
#define TERM_H
using namespace std;

struct Term
{
    double _coef;
    int _exp;

    Term(double coef, int exp);

    friend bool operator==(const Term &lhs, const Term &rhs);

    friend bool operator!=(const Term &lhs, const Term &rhs);

    friend bool operator>(const Term &lhs, const Term &rhs);

    friend bool operator<(const Term &lhs, const Term &rhs);

    friend Term operator+(const Term &lhs, const Term &rhs);

    friend Term operator-(const Term &t);

    friend Term operator-(const Term &lhs, const Term &rhs);

    friend Term operator*(const Term &lhs, const Term &rhs);

    friend Term operator/(const Term &lhs, const Term &rhs);

    friend ostream &operator<<(ostream &outs, const Term &t);
};

#endif