#include "rational.h"
#include "assert.h"


Rational::Rational(){
    _n = 0;
    _d = 1;
    _error = 0;
}
Rational::Rational(int num, int denom){
    _n = num;
    _d = denom;
    _error = is_error();
}
Rational::Rational(int w){
    _n = w;
    _d = 1;
    _error = 0;
}        //whole number

//mutators / setters
void Rational::set(int num, int denom){
    _n = num;
    _d = denom;
    _error = is_error();
}

void Rational::set_num(int n){
    _n = n;
}
void Rational::set_denom(int d){
    _d = d;
    _error = is_error();
}

//accessors / getters
int Rational::get_num() const{
    return _n;
}
int Rational::get_denom() const{
    return _d;
}

//error handling routines
int Rational::error() const{
    return _error;
}      //return error state

string Rational::error_description() const{
    string message = "No Error";
    if(is_error()){
        message = "Denominator is zero";
    }
    return message;
}   
                        //return a descriptive error message

void Rational::reset(){
    _n = 0;
    _d = 1;
    _error = 0;
}           //resets number to 0/1 and clears error state

//will return object whose error state is set 
//   if one of the operands is in error. 
Rational operator +(const Rational &num1, const Rational &num2){
    int _nNum1 = num1.get_num();
    int _nNum2 = num2.get_num();
    int _nDen1 = num1.get_denom();
    int _nDen2 = num2.get_denom();

    Rational addition((_nNum1 * _nDen2) + (_nNum2 * _nDen1), _nDen1 * _nDen2);
    if(num1.is_error()||num2.is_error())
    {
        addition._error = 1;
    }
    return addition;
}
Rational operator -(const Rational &num1, const Rational &num2){
    int _nNum1 = num1.get_num();
    int _nNum2 = num2.get_num();
    int _nDen1 = num1.get_denom();
    int _nDen2 = num2.get_denom();

    Rational subtract((_nNum1 * _nDen2) - (_nNum2 * _nDen1), _nDen1 * _nDen2);
    if(num1.is_error()||num2.is_error())
    {
        subtract._error = 1;
    }
    return subtract;
}
Rational operator *(const Rational &num1, const Rational &num2){
    int _nNum1 = num1.get_num();
    int _nNum2 = num2.get_num();
    int _nDen1 = num1.get_denom();
    int _nDen2 = num2.get_denom();

    Rational multiplication((_nNum1 * _nNum2), _nDen1 * _nDen2);
    if(num1.is_error()||num2.is_error())
    {
        multiplication._error = 1;
    }
    
    return multiplication;
}
Rational operator /(const Rational &num1, const Rational &num2){
    int _nNum1 = num1.get_num();
    int _nNum2 = num2.get_num();
    int _nDen1 = num1.get_denom();
    int _nDen2 = num2.get_denom();

    Rational multiplication((_nNum1 * _nDen2), _nDen1 * _nNum2);
    if(num1.is_error()||num2.is_error())
    {
        multiplication._error = 1;
    }
    return multiplication;
}

//will print UNDEFINED if num is in error.
ostream& operator <<(ostream &outs, const Rational &num){
    if(!num.error())
        outs << "[" << num.get_num() << "/" << num.get_denom() << "]";
    else 
        outs << "UNDEFINED";
    return outs;
}

istream& operator >>(istream &ins, Rational &num){
    int n, d;
    char slash;
    ins >> n >> slash >> d;

    cout << "{" << n << "/" << d << "}";

    num.set_num(n);
    num.set_denom(d);


    return ins;
}


int Rational::is_error() const{
    if(_d == 0)
        return 1;
    return 0;
}   //checks for error cond and returns error code     


// int _n;                 //numerator
// int _d;                 //denominator
// int _error;             //error code