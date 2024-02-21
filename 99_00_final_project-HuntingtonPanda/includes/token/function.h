#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include "assert.h"
#include "constant.h"

#include "token.h"

class Function:public Token{
    public:
        Function(string fx = "X"):Token(fx, FUNCTION), func(fx){
            if(fx == "X"){
                inputAmt = 0;
                trigType = -1;
                isVariable = true;
            }else{
                isVariable = false;
                inputAmt = 1;
                if(fx == "sin"){
                    trigType = SIN;
                }else if(fx == "cos"){
                    trigType = COS;
                }else if(fx == "tan"){
                    trigType = TAN;
                }else if(fx == "sec"){
                    trigType = SEC;
                }else if(fx == "csc"){
                    trigType = CSC;
                }else if(fx == "cot"){
                    trigType = COT;
                }else if(fx == "log"){
                    trigType = LOG;
                }else if(fx == "pow"){
                    trigType = POW;
                }
            }
        }

        void print()const{cout << func;}

        bool getIsVariable(){
           return isVariable;
        }

        int getTrigType(){
           return trigType;
        }


    private:
        int inputAmt;
        int trigType;
        bool isVariable;
        string func;

};

#endif