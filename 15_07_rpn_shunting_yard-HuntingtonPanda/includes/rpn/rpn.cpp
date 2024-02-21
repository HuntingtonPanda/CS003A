#include "rpn.h"
#include "assert.h"

RPN::RPN():_postfix(){}

RPN::RPN(Queue<Token*> a):_postfix(a){}

void RPN::set_input(Queue<Token*> a){
    _postfix = a;
}

// double RPN::rpn(int varValue){
//     double temp = (double)varValue /1.0;
//     return rpn(temp);
// }

double RPN::operator()(double varValue){
    Stack<Token*> stack;
    Queue<Token*> tempPostfix(_postfix);

    Token* tokenIt;

    Integer* first;
    Integer* second;

    Operator* queueOper;

    Function* queueFunc;

    while(tempPostfix.begin() != tempPostfix.end()){
        tokenIt = tempPostfix.pop();
        
        switch(tokenIt->type()){
            case INTEGER: stack.push(tokenIt);
                          break;
            case FUNCTION:
                //cout << "Hello\n"; 
                queueFunc = static_cast<Function*>(tokenIt);
                if(queueFunc -> getIsVariable()){
                    //cout << "IM IN\n";
                    stack.push(new Integer(varValue));
                    //cout << "MISSION COMPLETE";
                }else{
                    first = static_cast<Integer*>(stack.pop());
                    double firstValue = first -> getVal();

                    switch(queueFunc -> getTrigType()){
                        case SIN: stack.push(new Integer(sin(firstValue)));
                                  break;
                        case COS: stack.push(new Integer(cos(firstValue)));
                                  break;
                        case TAN: stack.push(new Integer(tan(firstValue)));
                                  break;
                        case ASIN: stack.push(new Integer(asin(firstValue)));
                                   break;
                        case ACOS: stack.push(new Integer(acos(firstValue)));
                                   break;
                        case ATAN: stack.push(new Integer(atan(firstValue)));
                                   break;
                        default: //cout << "YOU SUCK\n";
                                assert(false);
                    }
                    //cout << "Bye";
                }
                break;
            case OPERATION:
                queueOper = static_cast<Operator*> (tokenIt);
                stack.push(queueOper -> eval(stack.pop(), stack.pop()));
                break;
            
            default: //cout << "YOU SUCK ALOT\n";
                    assert(false);

        }
    }

    first = static_cast<Integer*>(stack.pop());
    return first -> getVal();

}