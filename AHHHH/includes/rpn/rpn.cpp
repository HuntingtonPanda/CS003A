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
            case INTEGER: stack.push(tokenIt); //Pushes integer
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

                    switch(queueFunc -> getTrigType()){  //Evaluates trig
                        case SIN: stack.push(new Integer(sin(firstValue)));
                                  break;
                        case COS: stack.push(new Integer(cos(firstValue)));
                                  break;
                        case TAN: stack.push(new Integer(tan(firstValue)));
                                  break;
                        case SEC: stack.push(new Integer(1/cos(firstValue)));
                                   break;
                        case CSC: stack.push(new Integer(1/sin(firstValue)));
                                   break;
                        case COT: stack.push(new Integer(1/tan(firstValue)));
                                   break;
                        case LOG: stack.push(new Integer(log(firstValue)));
                                   break;
                        case POW: stack.push(new Integer(pow(static_cast<Integer*>(stack.pop())-> getVal(),firstValue)));
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