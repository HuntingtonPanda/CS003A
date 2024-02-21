#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iomanip>
#include <string>
#include "assert.h"

#include "../node/node.h"
#include "constant.h"

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"

class Tokenizer
{
    //I know what my type is, I know what my face looks like.
    public:
        Tokenizer(const string& s){
            double num = 0;
            int counter = 0;
            for(int i = 0; i < s.length(); i++){
                switch(s[i]){ //Converts strings to tokens
                    case '+': infix.push(new Operator("+"));
                              break;
                    case '-': infix.push(new Operator("-"));
                              break;
                    case '*': infix.push(new Operator("*"));
                              break;
                    case '/': infix.push(new Operator("/"));
                              break;
                    case '^': infix.push(new Operator("^"));
                              break;

                    case 'x':
                    case 'X':infix.push(new Function("X"));
                             break;

                    case 's': 
                    case 'c': 
                    case 't':
                    case 'p': infix.push(new Function(s.substr(i, 3)));
                              i += 2;
                              break;

                    case ',': break;
                              
                    case '(': infix.push(new LeftParen("("));
                              break;
                    case ')': infix.push(new RightParen(")"));
                              break;

                    default: if(isdigit(s[i])){
                                while((i+1) < s.length() && (isdigit(s[i+1]) || s[i+1] == '.')){
                                    counter++;
                                }
                                num = stod(s.substr(i, counter + 1));
                                infix.push(new Integer(num));
                                i += counter;
                                counter = 0;
                             }
                             break;
                }
            }
        }

        Queue<Token*> getInfix(){
            return infix;
        }
    private:
        Queue<Token*> infix;
        string input;
};

#endif