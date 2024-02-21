#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

class Rational
{
public:
    Rational();
    Rational(int num, int denom);
    Rational(int w);        //whole number

    //mutators / setters
    void set(int num, int denom);
    void set_num(int n);
    void set_denom(int d);
  
    //accessors / getters
    int get_num() const;
    int get_denom() const;

    //error handling routines
    int error() const;      //return error state
    string error_description() const;   
                            //return a descriptive error message
  
    void reset();           //resets number to 0/1 and clears error state

    //will return object whose error state is set 
    //   if one of the operands is in error. 
    friend Rational operator +(const Rational &num1, const Rational &num2);
    friend Rational operator -(const Rational &num1, const Rational &num2);
    friend Rational operator *(const Rational &num1, const Rational &num2);
    friend Rational operator /(const Rational &num1, const Rational &num2);
    
    //will print UNDEFINED if num is in error.
    friend ostream& operator <<(ostream &outs, const Rational &num);
    friend istream& operator >>(istream &ins, Rational &num);

private:
    int is_error() const;   //checks for error cond and returns error code     
    int _n;                 //numerator
    int _d;                 //denominator
    int _error;             //error code
};

#endif