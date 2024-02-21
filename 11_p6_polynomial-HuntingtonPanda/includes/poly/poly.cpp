#include <iostream>
#include <iomanip>
#include <math.h>
#include "term.h"
#include "poly.h"
#include "assert.h"
#include "../array_functions/array_functions.h"

using namespace std;

Poly::Poly() : _order(0)
{
    int size = _order + 1;
    _coefs = allocate<double>(size);
    *_coefs = 0.0;
}
Poly::Poly(double *coefs, int order) : _order(order)
{
    int size = _order + 1;
    _coefs = allocate<double>(size);
    copy_array(_coefs, coefs, size);

    fix_order();
}


Poly::Poly(const Poly &other) : _order(other._order)
{

    int size = _order + 1;
    _coefs = allocate<double>(size);
    copy_array(_coefs, other._coefs, size);

 
    fix_order();
}

Poly &Poly::operator=(const Poly &rhs)
{
    if (this != &rhs)
    {
      
        delete[] _coefs;
        _order = rhs._order;

        int size = _order + 1;
        _coefs = allocate<double>(_order + 1);
        copy_array(_coefs, rhs._coefs, size);
    }

    return *this;
}

Poly::~Poly()
{
    delete[] _coefs;
}

bool operator==(const Poly &lhs, const Poly &rhs)
{
    if (lhs._order != rhs._order)
        return false;
   
    for (int i = 0; i < lhs._order + 1; i++)
    {
        if (fabs(lhs[i]._coef - rhs[i]._coef) > 0.001)
            return false;
    }
    return true;
}

bool operator!=(const Poly &lhs, const Poly &rhs)
{
    return !(lhs == rhs);
}

bool operator>(const Poly &lhs, const Poly &rhs)
{
    if (lhs._order > rhs._order)
        return true;

    else if (lhs._order < rhs._order)
        return false;

    for (int i = rhs._order; i >= 0; i--)
    {
        if (lhs[i] > rhs[i])
            return true;

        else if (lhs[i] < rhs[i])
            return false;

    }

    return false;
}
bool operator<(const Poly &lhs, const Poly &rhs)
{
    return !(lhs > rhs);
}

Term Poly::operator[](int order) const
{

    double *walker = _coefs + order;

    Term t(*walker, order);
    return t;
}

Poly operator+(const Poly &lhs, const Term &t)
{
    Poly result(lhs);                                 
   
    double *walker;

    if (t._exp > result._order)
    {
        // cout << "reallocate fired\n";
        result._coefs = reallocate(result._coefs, result._order + 1, t._exp + 1);
        
        result._order = t._exp;

        // walker = result._coefs + t._exp;
        // *walker = 0;
    }
    
    walker = result._coefs + t._exp;

    *walker += t._coef;

    //cout << *walker << endl;
    return result;
}

Poly operator+(const Poly &lhs, const Poly &rhs)
{
    Poly temp(lhs);
    
    for (int i = 0; i <= rhs._order; i++)
    {
        temp = temp + rhs[i];
    }

    
    temp.fix_order();
    return temp;
}

Poly operator-(const Poly &p)
{
    int size = p._order + 1;
    Poly result(p);

   
    for (int i = 0; i < size; i++)
    {
        double *walker = result._coefs + i;
        *walker *= -1;
    }

    return result;
}

Poly operator-(const Poly &lhs, const Poly &rhs)
{
    Poly p = lhs + (-rhs);
    

    p.fix_order();
    return p;
}

Poly operator*(const Poly &lhs, const Term &t)
{ 
    Poly result;

    int order = lhs._order + t._exp;
    
    result._coefs = reallocate(result._coefs, 0, order + 1);
    result._order = order;

    double *walker = result._coefs + t._exp;

    for (int j = 0; j < lhs._order + 1; j++, walker++)
    {
        *walker = lhs[j]._coef * t._coef;
    }


    return result;
}

Poly operator*(const Poly &lhs, const Poly &rhs)
{
    int order = lhs._order + rhs._order;

    Poly p; 
    for (int i = 0; i < rhs._order + 1; i++)
    {
        p = p + (lhs * rhs[i]);
    }
    p.fix_order();
    return p;
}

Poly operator/(const Poly &lhs, const Poly &rhs)
{
    
    Poly result; 

    assert(rhs._order != 0 || rhs[0]._coef != 0);

    if (lhs._order < rhs._order)
        return result;

    int order = lhs._order - rhs._order;
    int size = order + 1;              
    int curr_size = result._order + 1; 
    result._coefs = reallocate(result._coefs, curr_size, size);
    result._order = order;

    Poly dividend(lhs);

    while (dividend._order >= rhs._order && !(*dividend._coefs == 0 && dividend._order == 0))
    {

        int d_order = dividend._order;
        int r_order = rhs._order;

        
        int exp_diff = d_order - r_order;
        double ratio = dividend[d_order]._coef / rhs[r_order]._coef;

        double *walker = result._coefs + exp_diff;
        *walker = ratio;

        Term q(ratio, exp_diff);

        
        dividend = dividend - (rhs * q);
    } 

    result.fix_order();
    return result;
}

Poly operator%(const Poly &lhs, const Poly &rhs)
{
    Poly div = lhs / rhs;
    return lhs - (div * rhs);
}

ostream &operator<<(ostream &outs, const Poly &p)
{
    outs << "[ ";
    for (int i = p._order; i >= 0; i--)
    {
        outs << fixed << setprecision(1) << p[i];
    }
    outs << "] ";
    return outs;
}

istream &operator>>(istream &ins, Poly &p)
{
   
    Poly temp_poly;
    p = temp_poly;


    double coefficient;
    int exponent;

    char c;

  
    while (ins >> coefficient >> c >> exponent)
    {
        Term t(coefficient, exponent);
        p = p + t;

        if (ins.peek() == '\n')
        {
            break;
        }
    }

    return ins;
}

double *Poly::get_coefs() const
{
    return _coefs;
}

void Poly::set_order(int new_order)
{

    _order = new_order;
} 

void Poly::fix_order()
{

    double *ptr = _coefs + _order;

    for (int i = _order; i > 0; i--, ptr--)
    {
        if (*ptr == 0)
            _order--;
        else
            break;
    }
}