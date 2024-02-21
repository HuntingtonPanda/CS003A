#ifndef POLY_H
#define POLY_H

#include "term.h"

#include <iostream>
#include <vector>

using namespace std;

class Poly
{
public:
    Poly();
    Poly(double *coefs, int order);

    // the BIG 3
    Poly(const Poly &other);
    Poly &operator=(const Poly &rhs);
    ~Poly();

    friend bool operator==(const Poly &lhs, const Poly &rhs);

    friend bool operator!=(const Poly &lhs, const Poly &rhs);

    friend bool operator>(const Poly &lhs, const Poly &rhs);

    friend bool operator<(const Poly &lhs, const Poly &rhs);

    Term operator[](int order) const;

    friend Poly operator+(const Poly &lhs, const Term &t);
    
    friend Poly operator+(const Poly &lhs, const Poly &rhs);
   
    friend Poly operator-(const Poly &p);

    friend Poly operator-(const Poly &lhs, const Poly &rhs);

    friend Poly operator*(const Poly &lhs, const Term &t);

    friend Poly operator*(const Poly &lhs, const Poly &rhs);

    friend Poly operator/(const Poly &lhs, const Poly &rhs);

    friend Poly operator%(const Poly &lhs, const Poly &rhs);

    friend ostream &operator<<(ostream &outs, const Poly &p);

    friend istream &operator>>(istream &ins, Poly &p);

    double *get_coefs() const;
    int order() const { return _order; }
    void set_order(int new_order); 
    void fix_order();              
private:
    int _order;
    double *_coefs;
};

#endif