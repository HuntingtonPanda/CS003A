#include "poly.h"
#include "assert.h"

    void Poly::fixOrder(){
    List<Term>:: Iterator it;
    for(it = _poly.begin(); it != _poly.end(); it++){
        if(it->_coef == 0)
            _poly.Delete(it);
    }
    
    if(_poly.begin() == _poly.end())
        _poly.insert(Term(0,0));

    _order = _poly.begin()->_exp;

    }

    Poly::Poly(): _order(0), _poly(false, true){
        _poly.insert(Term(0,0));
    }
    Poly::Poly(double *term_array, int order): _order(order), _poly(false, true){
        double* walker = term_array;
        for(int i = 0; i <= order; i++, walker++){
            _poly.insert(Term(*walker, i));
        }
        fixOrder();
    }
    Poly::Poly(const vector<double>& terms): _poly(false, true){
        terms.size() ? _order = (terms.size()-1) : _order = 0;
        for(int i = 0; i < terms.size(); i++){
            _poly.insert(Term(terms[i], i));
        }
        fixOrder();
    }
    //big three?

    Poly& Poly::operator +=(const Term& t){
        _poly.insert_and_add(Term(t._coef, t._exp));

        return *this;
    }
    
    Poly& Poly::operator *=(const Term& t){
    
    _order += t._exp;

    List<Term>:: Iterator it;
    for(it = _poly.begin(); it != _poly.end(); it++){
        it->_coef *= t._coef;
    }

    fixOrder();

    return *this;

    }

    Poly& Poly::operator +=(const Poly& RHS){
    
    List<Term>:: Iterator it;
    for(it = RHS._poly.begin(); it != RHS._poly.end(); it++){
        *this += *it;
    }

    fixOrder();

    return *this;
    }

    Poly& Poly::operator *=(const Poly& RHS){
    
    List<Term>:: Iterator it;
    for(it = RHS._poly.begin(); it != RHS._poly.end(); it++){
        *this *= *it;
    }

    return *this;
    }

    Poly& Poly::operator -=(const Poly& RHS){
        
    List<Term>:: Iterator it;

    for(it = RHS._poly.begin(); it != RHS._poly.end(); it++){
        *this += -(*it); 
    }                       

    fixOrder();

    return *this;
    }

    bool operator==(const Poly &left, const Poly &right){
        return left._order == right._order;
    }
    bool operator!=(const Poly &left, const Poly &right){
        return left._order != right._order;
    }

    Poly operator+(const Poly &left, const Poly &right){
        Poly temp(left);
        return temp += right;
    }
    Poly operator -(const Poly& left, const Poly& right){
        Poly temp(left);
        return temp -= right;
    }
    Poly operator * (const Poly& left, const Poly& right){
        Poly temp(left);
        return temp *= right;
    }
    Poly operator/(const Poly &left, const Poly &right){
        Poly result; 

        return result;
    }
    Poly operator%(const Poly &left, const Poly &right){
        Poly div = left / right;
        return left - (div * right);
    }
    
    Poly Poly::operator-() const{
        Poly result(*this);

        List<Term>:: Iterator it;

        for(it = result._poly.begin(); it != result._poly.end(); it++){
        *it = -(*it); 
        }    

        return result;

    }

    Poly operator + (const Poly& left, const Term& t){
        Poly result(left);
        result._poly.insert_and_add(t);

        return result;
    }
    Poly operator * (const Poly& left, const Term& t){
        Poly result(left);
        result *= t;

        return result;
    }

    ostream& operator << (ostream& outs, const Poly& print_me){
        List<Term>:: Iterator it;

        outs << "[ ";
        for(it = print_me._poly.begin(); it != print_me._poly.end(); it++){
            outs << fixed << setprecision(1) << it->_coef;
        }
        outs << "] ";

        return outs;
    }
    istream& operator >> (istream& outs, Poly& read_me){
        Poly temp_poly;
        read_me = temp_poly;


        double coefficient;
        int exponent;

        char c;

    
        while (outs >> coefficient >> c >> exponent)
        {
            Term t(coefficient, exponent);
            read_me = read_me + t;

            if (outs.peek() == '\n')
            {
                break;
            }
        }

        return outs;
    }

    const Term& Poly::operator [](const int exp) const{
        return (*this)[exp];
    }
    Term& Poly::operator [](const int exp){
        List<Term>:: Iterator it;

        for(it = _poly.begin(); it != _poly.end(); it++){
            if(it->_coef ==exp)
                return *it;
        }  

        return *(_poly.insert(Term(0, exp)));
    }
   